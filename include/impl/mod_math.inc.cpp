#ifndef MOD_MATH_IMPL_MOD_MATH_INC_CPP
#define MOD_MATH_IMPL_MOD_MATH_INC_CPP

#include "mod_math.hpp"

namespace mod_math {
template <std::integral T>
constexpr num<T>::num(const T& val) : val(val){};

template <std::integral T>
constexpr num<T>::operator T() const {
	return this->val;
}

template <std::integral T>
constexpr auto num<T>::operator<=>(const num<T>& other) const {
	return this->val <=> other.val;
}

namespace literals {
constexpr num<unsigned long long> operator""_mod(unsigned long long val) {
	return num<unsigned long long>{val};
}
}  // namespace literals
}  // namespace mod_math

#endif  // #ifndef MOD_MATH_IMPL_MOD_MATH_INC_CPP
