#ifndef MOD_MATH_IMPL_MOD_MATH_INC_CPP
#define MOD_MATH_IMPL_MOD_MATH_INC_CPP

#include "mod_math.hpp"

namespace mod_math {
// ==========================
// class num<T>
// ==========================

template <std::integral T>
constexpr void num<T>::apply_mod(const T& mod) {
	if (!last_mod.has_value() || ((*last_mod > mod) && (val > mod))) val %= mod;

	last_mod = mod;
}

template <std::integral T>
constexpr num<T>::num(const T& val) : val(val){};

template <std::integral T>
template <std::integral U>
constexpr num<T>::num(const num<U>& other) : num(static_cast<T>(other.val)){};

template <std::integral T>
template <std::integral U>
constexpr num<T>& num<T>::operator=(const num<U>& other) {
	this->val = static_cast<T>(other.val);

	return *this;
}

template <std::integral T>
constexpr num<T>::operator T() const {
	return this->val;
}

template <std::integral T>
constexpr std::strong_ordering num<T>::operator<=>(const num<T>& other) const {
	return this->val <=> other.val;
}

template <std::integral T>
template <std::integral U>
constexpr std::strong_ordering num<T>::operator<=>(const num<U>& other) const {
	using X = typename std::common_type_t<T, U>;

	const num<X> rhs(*this);
	const num<X> lhs(other);

	return rhs <=> lhs;
}

template <std::integral T>
constexpr expr<T> num<T>::operator+(const num<T>& other) const {
	expr<T> var{num<T>{other}};

	return operator+(var);
}

template <std::integral T>
constexpr expr<T> num<T>::operator+(const expr<T>& other) const {
	return expr<T>(expr<T>(*this), other, operator+);
}

// ==========================
// class expr<T>
// ==========================

template <std::integral T>
constexpr expr<T>::expr(const expr<T>& param1, const expr<T>& param2,
                        const std::function<T(const T&, const T&)>& action)
    : param1(&param1), param2(&param2), action(&action), val(nullptr) {}

template <std::integral T>
constexpr expr<T>::expr(num<T>& val) : param1(nullptr), param2(nullptr), action(nullptr), val(&val) {}

template <std::integral T>
constexpr void expr<T>::apply_mod(const T& mod) const {
	if (param1 == nullptr) {
		val->apply_mod(mod);
	} else {
		param1->apply_mod(mod);
		param2->apply_mod(mod);
	}

	last_mod = mod;
}

template <std::integral T>
constexpr expr<T>::operator T() const {
	if (param1 == nullptr) {
		return static_cast<T>(*val);
	} else {
		return (*action)(static_cast<T>(*param1), static_cast<T>(*param2));
	}
}

template <std::integral T>
constexpr expr<T>::operator num<T>() const {
	num<T> res{static_cast<T>(*this)};
	res.last_mod = this->last_mod;

	return res;
}

template <std::integral T>
constexpr expr<T> expr<T>::operator+(const num<T>& other) const {
	return operator+(expr<T>(other));
}

template <std::integral T>
constexpr expr<T> expr<T>::operator+(const expr<T>& other) const {
	return expr<T>(*this, other, operator+);
}

namespace literals {
constexpr num<unsigned long long> operator""_mod(unsigned long long val) {
	return num<unsigned long long>{val};
}
}  // namespace literals
}  // namespace mod_math

#endif  // #ifndef MOD_MATH_IMPL_MOD_MATH_INC_CPP
