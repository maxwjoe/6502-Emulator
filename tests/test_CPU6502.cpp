#include <iostream>
#include "gtest/gtest.h"

// === Generic test to check google test working correctly ===

// simple_expect_pass (Should be passing)
TEST(example, simple_expect_pass)
{
    float x = 5.0f;
    EXPECT_TRUE(x == 5.0f);
}

// simple_expect_fail (Should be failing)
TEST(example, simple_expect_fail)
{
    float y = 7.3f;
    EXPECT_TRUE(y == 8.1f);
}