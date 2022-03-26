#ifndef MOD_MATH_IMPL_MOD_MATH_INC_CPP
#define MOD_MATH_IMPL_MOD_MATH_INC_CPP

#include "mod_math.hpp"

namespace mod_math {
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

namespace literals {
constexpr num<unsigned long long> operator""_mod(unsigned long long val) {
	return num<unsigned long long>{val};
}
}  // namespace literals
}  // namespace mod_math

#endif  // #ifndef MOD_MATH_IMPL_MOD_MATH_INC_CPP
