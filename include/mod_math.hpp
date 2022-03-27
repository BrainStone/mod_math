#pragma once

#include <compare>
#include <concepts>
#include <functional>
#include <optional>
#include <type_traits>

namespace mod_math {
template <std::integral T>
class expr;

template <std::integral T>
class num {
private:
	T val;
	std::optional<T> last_mod{};

	constexpr void apply_mod(const T& mod);

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

	constexpr expr<T> operator+(const num<T>& other) const;
	constexpr expr<T> operator+(const expr<T>& other) const;

	// We're friends with outselves
	template <std::integral U>
	friend class num;
	friend class expr<T>;
};

template <std::integral T>
class expr {
private:
	const expr<T>* const param1;
	const expr<T>* const param2;
	const std::function<T(const T&, const T&)>* const action;
	num<T>* const val;
	std::optional<T> last_mod{};

	constexpr expr(const expr<T>& param1, const expr<T>& param2, const std::function<T(const T&, const T&)>& action);
	constexpr expr(num<T>& val);

	constexpr void apply_mod(const T& mod) const;

public:
	constexpr expr(const expr<T>& other) = delete;
	constexpr expr(expr<T>&& other) = delete;

	constexpr expr<T>& operator=(const expr<T>& other) = delete;
	constexpr expr<T>& operator=(expr<T>&& other) = delete;

	constexpr operator T() const;
	constexpr operator num<T>() const;

	constexpr expr<T> operator+(const num<T>& other) const;
	constexpr expr<T> operator+(const expr<T>& other) const;

	friend class num<T>;
};

namespace literals {
constexpr num<unsigned long long> operator""_mod(unsigned long long val);
}
}  // namespace mod_math

// Include definitions
#include "impl/mod_math.inc.cpp"
