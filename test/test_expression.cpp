#include "test_common.hpp"

TEST(Expression, Add) {
	mod_math::num<std::uint64_t> var1 = 123_mod;
	mod_math::num<std::uint64_t> var2 = 124_mod;

	mod_math::num<std::uint64_t> res = var1 + var2;

	EXPECT_EQ(res, 267_mod);
}
