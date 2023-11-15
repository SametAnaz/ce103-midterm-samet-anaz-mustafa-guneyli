/**
 * @file forestry.h
 *
 * @brief Provides functions for math utilities.
 */

#ifndef FORESTRY_H
#define FORESTRY_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "../../utility/header/commonTypes.h"

struct Tree {
  std::string species;
  std::string age;
  std::string quantity;
};

struct ForestryData {
  std::vector<Tree> trees;
  std::unordered_map<std::string, Tree> treeHashMap;
};

extern ForestryData forestryData;

int addTree(const Tree &tree);
int registration();
int saveTreesToFile();
int loadTreesFromFile();
int updateTrees();
int listTreesFromFile();
int updateTreeAtIndex();
int enterForMenu();
int returnToMainMenu();
#endif // FORESTRY_H
