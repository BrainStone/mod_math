#include "test_common.hpp"

TEST(Comparison, ConstexprSpaceship) {
	constexpr mod_math::num<std::uint64_t> var1{123};
	constexpr mod_math::num<std::uint64_t> var2{123};
	constexpr mod_math::num<std::uint64_t> var3{124};

	EXPECT_EQ(var1 <=> var2, std::strong_ordering::equal);
	EXPECT_EQ(var1 <=> var3, std::strong_ordering::less);
}

TEST(Comparison, Spaceship) {
	mod_math::num<std::uint64_t> var1{123};
	mod_math::num<std::uint64_t> var2{123};
	mod_math::num<std::uint64_t> var3{124};

	EXPECT_EQ(var1 <=> var2, std::strong_ordering::equal);
	EXPECT_EQ(var1 <=> var3, std::strong_ordering::less);
}

TEST(Comparison, ConstexprEquals) {
	constexpr mod_math::num<std::uint64_t> var1{123};
	constexpr mod_math::num<std::uint64_t> var2{123};

	EXPECT_EQ(var1, var2);
}

TEST(Comparison, Equals) {
	mod_math::num<std::uint64_t> var1{123};
	mod_math::num<std::uint64_t> var2{123};

	EXPECT_EQ(var1, var2);
}

TEST(Comparison, ConstexprLess) {
	constexpr mod_math::num<std::uint64_t> var1{123};
	constexpr mod_math::num<std::uint64_t> var2{124};

	EXPECT_LT(var1, var2);
}

TEST(Comparison, Less) {
	mod_math::num<std::uint64_t> var1{123};
	mod_math::num<std::uint64_t> var2{124};

	EXPECT_LT(var1, var2);
}

TEST(Comparison, ConstexprSpaceshipMixed) {
	constexpr mod_math::num<std::uint64_t> var1{123};
	constexpr mod_math::num<std::uint32_t> var2{123};
	constexpr mod_math::num<std::uint32_t> var3{124};

	EXPECT_EQ(var1 <=> var2, std::strong_ordering::equal);
	EXPECT_EQ(var1 <=> var3, std::strong_ordering::less);
	EXPECT_EQ(var2 <=> var1, std::strong_ordering::equal);
	EXPECT_EQ(var3 <=> var1, std::strong_ordering::greater);
}

TEST(Comparison, SpaceshipMixed) {
	mod_math::num<std::uint64_t> var1{123};
	mod_math::num<std::uint32_t> var2{123};
	mod_math::num<std::uint32_t> var3{124};

	EXPECT_EQ(var1 <=> var2, std::strong_ordering::equal);
	EXPECT_EQ(var1 <=> var3, std::strong_ordering::less);
	EXPECT_EQ(var2 <=> var1, std::strong_ordering::equal);
	EXPECT_EQ(var3 <=> var1, std::strong_ordering::greater);
}

TEST(Comparison, ConstexprEqualsMixed) {
	constexpr mod_math::num<std::uint64_t> var1{123};
	constexpr mod_math::num<std::uint32_t> var2{123};

	EXPECT_EQ(var1, var2);
	EXPECT_EQ(var2, var1);
}

TEST(Comparison, EqualsMixed) {
	mod_math::num<std::uint64_t> var1{123};
	mod_math::num<std::uint32_t> var2{123};

	EXPECT_EQ(var1, var2);
	EXPECT_EQ(var2, var1);
}

TEST(Comparison, ConstexprLessMixed) {
	constexpr mod_math::num<std::uint64_t> var1{123};
	constexpr mod_math::num<std::uint32_t> var2{124};

	EXPECT_LT(var1, var2);
	EXPECT_GT(var2, var1);
}

TEST(Comparison, LessMixed) {
	mod_math::num<std::uint64_t> var1{123};
	mod_math::num<std::uint32_t> var2{124};

	EXPECT_LT(var1, var2);
	EXPECT_GT(var2, var1);
}
