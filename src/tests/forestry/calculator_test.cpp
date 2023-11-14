//#define ENABLE_FORESTRY_TEST  // Uncomment this line to enable the Forestry tests

#include <vector>
#include <gtest/gtest.h>
#include "forestry.h"

// Test addTree function
TEST(AddTreeTest, AddTreeSuccess) {
  Tree testTree{ "TestSpecies", "5", "10" };
  int result = addTree(testTree);
  ASSERT_EQ(result, 0);
  // You can add additional checks if needed
}

// Test registration function
TEST(RegistrationTest, RegistrationSuccess) {
  // Mock user input for testing
  std::istringstream mockInput("TestSpecies\n5\n10\n");
  std::cin.rdbuf(mockInput.rdbuf());
  int result = registration();
  ASSERT_EQ(result, 0);
  // You can add additional checks if needed
}

// Test loadTreesFromFile function
TEST(LoadTreesFromFileTest, LoadTreesFromFileSuccess) {
  int result = loadTreesFromFile();
  ASSERT_EQ(result, 0);
  // You can add additional checks if needed
}

// Test saveTreesToFile function
TEST(SaveTreesToFileTest, SaveTreesToFileSuccess) {
  int result = saveTreesToFile();
  ASSERT_EQ(result, 0);
  // You can add additional checks if needed
}

// Test updateTrees function
TEST(UpdateTreesTest, UpdateTreesSuccess) {
  // Mock user input for testing
  std::istringstream mockInput("UpdatedSpecies\n6\n15\n");
  std::cin.rdbuf(mockInput.rdbuf());
  int result = updateTrees();
  ASSERT_EQ(result, 0);
  // You can add additional checks if needed
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
