#pragma once

#include <compare>
#include <concepts>

namespace mod_math {
template <std::integral T>
class expr;

template <std::integral T>
class num {
private:
	T val;

public:
	constexpr num() = default;
	constexpr num(const T& val);
	constexpr num(const num<T>& other) = default;
	constexpr num(num<T>&& other) = default;

	constexpr num<T>& operator=(const num<T>& other) = default;
	constexpr num<T>& operator=(num<T>&& other) = default;

	constexpr operator T() const;

	constexpr auto operator<=>(const num<T>& other) const;
};

namespace literals {
constexpr num<unsigned long long> operator""_mod(unsigned long long val);
}
}  // namespace mod_math

// Include definitions
#include "impl/mod_math.inc.cpp"
