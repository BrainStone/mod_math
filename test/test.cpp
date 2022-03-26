#include "gtest/gtest.h"
#include "mod_math.hpp"

using namespace mod_math::literals;

TEST(Constructor, constexpr_literal) {
	constexpr mod_math::num<std::uint64_t> ref{123};

	constexpr mod_math::num<std::uint64_t> var1 = 123_mod;
	constexpr mod_math::num<std::uint64_t> var2 = 124_mod;

	EXPECT_EQ(var1, ref);
	EXPECT_NE(var2, ref);
}

TEST(Constructor, literal) {
	mod_math::num<std::uint64_t> ref{123};

	mod_math::num<std::uint64_t> var1 = 123_mod;
	mod_math::num<std::uint64_t> var2 = 124_mod;

	EXPECT_EQ(var1, ref);
	EXPECT_NE(var2, ref);
}
