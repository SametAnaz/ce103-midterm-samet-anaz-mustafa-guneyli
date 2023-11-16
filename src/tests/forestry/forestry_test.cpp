//#define ENABLE_FORESTRY_TEST  // Uncomment this line to enable the Forestry tests

#include <vector>
#include <gtest/gtest.h>
#include "forestry.h"

class ForestryTest : public ::testing::Test {
 protected:
  // Set up the test fixture
  void SetUp() override {
    // You can add any setup code specific to the tests
  }

  // Tear down the test fixture
  void TearDown() override {
    // You can add any tear down code specific to the tests
  }
};


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
  ASSERT_EQ(result, -1);
  // You can add additional checks if needed
}

// Test the listTreesFromFile function
TEST_F(ForestryTest, ListTreesFromFile) {
  // Add test data to the forestryData.trees vector
  addTree(Tree{ "TestSpecies1", "TestAge1", "TestQuantity1" });
  addTree(Tree{ "TestSpecies2", "TestAge2", "TestQuantity2" });
  addTree(Tree{ "TestSpecies3", "TestAge3", "TestQuantity3" });
  // Redirect std::cout to a stringstream to capture the output
  std::stringstream buffer;
  std::streambuf *oldCout = std::cout.rdbuf(buffer.rdbuf());
  // Call the listTreesFromFile function
  int result = listTreesFromFile();
  // Reset std::cout to the original buffer
  std::cout.rdbuf(oldCout);
  // Check if the output contains the expected information
  EXPECT_EQ(result, 0);
  std::string output = buffer.str();
  // Check if the output contains the expected information
  EXPECT_TRUE(output.find("1. TestSpecies1, TestAge1, TestQuantity1") != std::string::npos);
  EXPECT_TRUE(output.find("2. TestSpecies2, TestAge2, TestQuantity2") != std::string::npos);
  EXPECT_TRUE(output.find("3. TestSpecies3, TestAge3, TestQuantity3") != std::string::npos);
}

// Test deleteTreeAtIndex function
TEST(DeleteTreeAtIndexTest, DeleteTreeAtIndexSuccess) {
  // Add test data to forestryData.trees vector
  addTree(Tree{ "TestSpecies1", "5", "10" });
  addTree(Tree{ "TestSpecies2", "6", "15" });
  // Delete the first tree
  int result = deleteTreeAtIndex(0);
  ASSERT_EQ(result, 0);
  // Load trees from the temporary file
  loadTreesFromFile();
  // Check if the tree is deleted correctly
  ASSERT_EQ(forestryData.trees.size(), 1);
  ASSERT_EQ(forestryData.trees[0].species, "echo TestSpecies2");
  ASSERT_EQ(forestryData.trees[0].age, "6");
  ASSERT_EQ(forestryData.trees[0].quantity, "15");
}

// Test deleteTree function
TEST(DeleteTreeTest, DeleteTreeSuccess) {
  // Add test data to forestryData.trees vector
  addTree(Tree{ "TestSpecies1", "5", "10" });
  addTree(Tree{ "TestSpecies2", "6", "15" });
  // Mock user input for testing
  std::istringstream mockInput("1\n");  // Delete the first tree
  std::cin.rdbuf(mockInput.rdbuf());
  // Delete the selected tree
  int result = deleteTree();
  ASSERT_EQ(result, 0);
  // Load trees from the temporary file
  loadTreesFromFile();
  // Check if the tree is deleted correctly
  ASSERT_EQ(forestryData.trees.size(), 0);
  ASSERT_EQ(forestryData.trees[0].species, "echo TestSpecies2");
  ASSERT_EQ(forestryData.trees[0].age, "6");
  ASSERT_EQ(forestryData.trees[0].quantity, "15");
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
