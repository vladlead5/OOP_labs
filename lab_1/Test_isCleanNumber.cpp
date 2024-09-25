#include <gtest/gtest.h>
#include "isCleanNumber.h"

TEST(IsCleanNumberTest, CleanNumber) {
    EXPECT_TRUE(isCleanNumber(123));
    EXPECT_TRUE(isCleanNumber(135));
}

TEST(IsCleanNumberTest, NotCleanNumber) {
    EXPECT_FALSE(isCleanNumber(321));
    EXPECT_FALSE(isCleanNumber(543));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
