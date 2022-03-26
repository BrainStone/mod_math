#include "test_common.hpp"

TEST(Constructor, ConstexprLiteral) {
	constexpr mod_math::num<std::uint64_t> ref{123};

	constexpr mod_math::num<std::uint64_t> var1 = 123_mod;
	constexpr mod_math::num<std::uint64_t> var2 = 124_mod;

	EXPECT_EQ(var1, ref);
	EXPECT_NE(var2, ref);
	EXPECT_GT(var2, ref);
}

TEST(Constructor, Literal) {
	mod_math::num<std::uint64_t> ref{123};

	mod_math::num<std::uint64_t> var1 = 123_mod;
	mod_math::num<std::uint64_t> var2 = 124_mod;

	EXPECT_EQ(var1, ref);
	EXPECT_NE(var2, ref);
	EXPECT_GT(var2, ref);
}

TEST(Constructor, ConstexprMixed) {
	constexpr mod_math::num<std::uint64_t> var1{123};
	constexpr mod_math::num<std::uint32_t> var2{var1};
	constexpr mod_math::num<std::uint64_t> var3{var2};

	EXPECT_EQ(var1, var3);
}

TEST(Constructor, Mixed) {
	mod_math::num<std::uint64_t> var1{123};
	mod_math::num<std::uint32_t> var2{var1};
	mod_math::num<std::uint64_t> var3{var2};

	EXPECT_EQ(var1, var3);
}
