#include "../badfunc.cc"
#include <gtest/gtest.h>

TEST(FactTest, SmallNumbers) {
	ASSERT_EQ(1, fact(0)); // these tests will catch the function being buggy
	ASSERT_EQ(1, fact(1));
	ASSERT_EQ(2, fact(2));
	ASSERT_EQ(6, fact(3));
	ASSERT_EQ(24, fact(4));
	ASSERT_EQ(120, fact(5));
	ASSERT_EQ(720, fact(6));
	ASSERT_EQ(5040, fact(7));
}

TEST(FactTest, Negative) {
	ASSERT_EQ(1, fact(-1));
}

TEST(FactTest, BigNumbers) {
	ASSERT_EQ(1.3076744e+12, fact(15)); // this is a bad test
}

int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

	
