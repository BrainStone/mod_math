#include "gtest/gtest.h"
#include "mod_math.hpp"

TEST(mod_math, add) {
	EXPECT_EQ(add(1, 2), 3);
}
