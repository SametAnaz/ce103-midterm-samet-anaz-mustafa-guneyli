#include <cstdlib>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "forestry.h"

// ForestryData adlı bir yapı tanımla
ForestryData forestryData;

int addTree(const Tree &tree) {
  forestryData.trees.push_back(tree);  // forestryData.trees kullanıldı
  forestryData.treeHashMap[tree.species] = tree;
  // Başarı durumunda 0 döndür
  return 0;
}

int loadTreesFromFile() {
  std::string filename = "treeinfo.txt";
  std::ifstream file(filename);

  if (file.is_open()) {
    forestryData.trees.clear(); // forestryData.trees kullanıldı
    std::string line;

    while (std::getline(file, line)) {
      std::istringstream linestream(line);
      std::string species, age, quantity;
      std::getline(linestream, species, ',');
      std::getline(linestream, age, ',');
      std::getline(linestream, quantity, ',');
      forestryData.trees.push_back({ species, age, quantity });  // forestryData.trees kullanıldı
    }

    file.close();
    std::cout << "Members have been loaded from " << filename << std::endl;
    return 0; // Başarı durumunda 0 dön
  } else {
    std::cerr << "Failed to open the file for loading." << std::endl;
    return -1; // Hata durumunda -1 dön
  }
}

int registration() {
  std::string species, age, quantity;
  std::cout << "Enter Species: ";
  std::cin >> species;
  std::cout << "Enter Age: ";
  std::cin >> age;
  std::cout << "Enter Quantity: ";
  std::cin >> quantity;
  Tree newTree{ species, age, quantity };
  int result = addTree(newTree);
  // Hata durumunda -1 döndür
  return result;
}

int saveTreesToFile() {
  std::string filename = "treeinfo.txt";
  std::ofstream file(filename, std::ios::out | std::ios::trunc);

  if (file.is_open()) {
    for (const Tree &tree : forestryData.trees) {
      file << tree.species << "," << tree.age << "," << tree.quantity << "\n";
    }

    file.close();
    std::cout << "Tree information has been saved to " << filename << std::endl;
    return 0; // Başarı durumunda 0 dön
  } else {
    std::cerr << "Failed to open the file for saving." << std::endl;
    return -1; // Hata durumunda -1 dön
  }
}

int updateTrees() {
  if (loadTreesFromFile() != 0) {
    // Hata durumunda -1 döndür
    return -1;
  }

  int index = 0;

  for (Tree &tree : forestryData.trees) {
    std::string species, age, quantity;
    // Kullanıcıdan yeni verileri al
    std::cout << "Enter new species for tree " << index << ": ";
    std::cin >> species;
    std::cout << "Enter new age for tree " << index << ": ";
    std::cin >> age;
    std::cout << "Enter new quantity for tree " << index << ": ";
    std::cin >> quantity;
    // Verileri güncelle
    tree.species = species;
    tree.age = age;
    tree.quantity = quantity;
    ++index;
  }

  if (saveTreesToFile() != 0) {
    // Hata durumunda -1 döndür
    return -1;
  }

  return 0;
}
