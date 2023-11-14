//#define ENABLE_FORESTRY_TEST  // Uncomment this line to enable the Forestry tests

#include "gtest/gtest.h"
#include "../../forestry/header/forestry.h"  // Adjust this include path based on your project structure

using namespace Coruh::Forestry;

class ForestryTest : public ::testing::Test {
protected:
	void SetUp() override {
		// Setup test data
	}

	void TearDown() override {
		// Clean up test data
	}
};

TEST_F(ForestryTest, TestAdd) {
	double result = Forestry::add(5.0, 3.0);
	EXPECT_DOUBLE_EQ(result, 8.0);
}

TEST_F(ForestryTest, TestSubtract) {
	double result = Forestry::subtract(5.0, 3.0);
	EXPECT_DOUBLE_EQ(result, 2.0);
}

TEST_F(ForestryTest, TestMultiply) {
	double result = Forestry::multiply(5.0, 3.0);
	EXPECT_DOUBLE_EQ(result, 15.0);
}

TEST_F(ForestryTest, TestDivide) {
	double result = Forestry::divide(6.0, 3.0);
	EXPECT_DOUBLE_EQ(result, 2.0);
}

TEST_F(ForestryTest, TestDivideByZero) {
	EXPECT_THROW(Forestry::divide(5.0, 0.0), std::invalid_argument);
}

/**
 * @brief The main function of the test program.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line argument strings.
 * @return int The exit status of the program.
 */
int main(int argc, char** argv) {
#ifdef ENABLE_FORESTRY_TEST
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
#else
	return 0;
#endif
}