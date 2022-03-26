#pragma once

#include <compare>
#include <concepts>
#include <type_traits>

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
	template <std::integral U>
	constexpr num(const num<U>& other);
	constexpr num(num<T>&& other) = default;

	constexpr num<T>& operator=(const num<T>& other) = default;
	template <std::integral U>
	constexpr num<T>& operator=(const num<U>& other);
	constexpr num<T>& operator=(num<T>&& other) = default;

	constexpr operator T() const;

	constexpr std::strong_ordering operator<=>(const num<T>& other) const;
	template <std::integral U>
	constexpr std::strong_ordering operator<=>(const num<U>& other) const;

	// We're friends with outselves
	template <std::integral U>
	friend class num;
};

namespace literals {
constexpr num<unsigned long long> operator""_mod(unsigned long long val);
}
}  // namespace mod_math

// Include definitions
#include "impl/mod_math.inc.cpp"
