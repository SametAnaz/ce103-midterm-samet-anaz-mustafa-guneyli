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


int listTreesFromFile() {
    if (loadTreesFromFile() != 0) {
        return -1;
    }

    // Listeyi göster
    int index = 1;

    for (const Tree& tree : forestryData.trees) {
        std::cout << index << ". " << tree.species << ", " << tree.age << ", " << tree.quantity << std::endl;
        index++;
    }

    return 0; // Başarı durumunda 0 döndür
}

int loadTreesFromFile() {
    std::string filename = "treeinfo.bat";
    std::ifstream file(filename);

    if (file.is_open()) {
        forestryData.trees.clear();
        std::string line;

        while (std::getline(file, line)) {
            std::string species, age, quantity;
            size_t pos = line.find(",");
            species = line.substr(0, pos);
            line.erase(0, pos + 1);
            pos = line.find(",");
            age = line.substr(0, pos);
            line.erase(0, pos + 1);
            quantity = line;
            forestryData.trees.push_back({ species, age, quantity });
        }

        file.close();
        std::cout << "Members have been loaded from " << filename << std::endl;
        return 0;
    }
    else {
        std::cerr << "Failed to open the file for loading." << std::endl;
        return -1;
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
  std::string filename = "treeinfo.bat";
  std::ofstream file(filename, std::ios::out | std::ios::trunc);

  if (file.is_open()) {
    for (const Tree &tree : forestryData.trees) {
      file << "echo " << tree.species << "," << tree.age << "," << tree.quantity << "\n";
    }

    file.close();
    std::cout << "Tree information has been saved to " << filename << std::endl;
    return 0; // Başarı durumunda 0 dön
  } else {
    std::cerr << "Failed to open the file for saving." << std::endl;
    return -1; // Hata durumunda -1 dön
  }
}



int updateTreeAtIndex(int index) {
  if (index < 0 || index >= forestryData.trees.size()) {
    std::cerr << "Invalid index." << std::endl;
    return -1; // Hata durumunda -1 döndür
  }

  Tree &tree = forestryData.trees[index];
  std::string species, age, quantity;
  std::cout << "Enter new species for tree " << index << ": ";
  std::cin >> species;
  std::cout << "Enter new age for tree " << index << ": ";
  std::cin >> age;
  std::cout << "Enter new quantity for tree " << index << ": ";
  std::cin >> quantity;
  tree.species = species;
  tree.age = age;
  tree.quantity = quantity;

  if (saveTreesToFile() != 0) {
    return -1; // Hata durumunda -1 döndür
  }

  return 0;
}


int updateTrees() {
  if (loadTreesFromFile() != 0) {
    return -1;
  }

  // Listeyi göster
  int index = 1;

  for (const Tree &tree : forestryData.trees) {
    std::cout << index << ". " << tree.species << ", " << tree.age << ", " << tree.quantity << std::endl;
    index++;
  }

  int selectedTreeIndex;
  std::cout << "Enter the index of the tree to update: ";
  std::cin >> selectedTreeIndex;

  if (selectedTreeIndex <= 0 || selectedTreeIndex > forestryData.trees.size()) {
    std::cerr << "Invalid index." << std::endl;
    return -1;
  }

  // Seçilen ağacın indeksi
  int treeIndex = selectedTreeIndex - 1;
  // Seçilen ağacın bilgilerini güncelle
  int result = updateTreeAtIndex(treeIndex);

  if (result != 0) {
    return -1;
  }

  return 0;
}
int enterForMenu() {
  std::cout << "Press any key to return to the menu...";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Önceki girişi temizle
  std::cin.get(); // Yeni girişi bekleyerek devam et
  return 0;
}


int deleteTreeAtIndex(int index) {
  if (index < 0 || index >= forestryData.trees.size()) {
    std::cerr << "Invalid index." << std::endl;
    return -1; // Hata durumunda -1 döndür
  }

  // Sileceğimiz ağacın bilgilerini ekrana yazdır
  const Tree &treeToDelete = forestryData.trees[index];
  std::cout << "Deleting tree: " << treeToDelete.species << ", " << treeToDelete.age << ", " << treeToDelete.quantity << std::endl;
  // İlgili ağacı vektörden sil
  forestryData.trees.erase(forestryData.trees.begin() + index);

  // Dosyaya değişiklikleri kaydet
  if (saveTreesToFile() != 0) {
    return -1; // Hata durumunda -1 döndür
  }

  return 0;
}

int deleteTree() {
  if (loadTreesFromFile() != 0) {
    return -1;
  }

  // Listeyi göster
  int index = 1;

  for (const Tree &tree : forestryData.trees) {
    std::cout << index << ". " << tree.species << ", " << tree.age << ", " << tree.quantity << std::endl;
    index++;
  }

  int selectedTreeIndex;
  std::cout << "Enter the index of the tree to delete: ";
  std::cin >> selectedTreeIndex;

  if (selectedTreeIndex <= 0 || selectedTreeIndex > forestryData.trees.size()) {
    std::cerr << "Invalid index." << std::endl;
    return -1;
  }

  // Seçilen ağacın indeksi
  int treeIndex = selectedTreeIndex - 1;
  // Seçilen ağacı sil
  int result = deleteTreeAtIndex(treeIndex);

  if (result != 0) {
    return -1;
  }

  return 0;
}




int returnToMainMenu() {
  std::cout << "Returning to the main menu..." << std::endl;
  std::cout << "Press any key to continue...";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cin.get();
  return -1; // Ana menüye dönmek için -1 dön
}
