#include <cstdlib>
#include <stdexcept>
#include <fstream>
#include <list>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map> 
#include <stack>
#include <queue>
#include <fstream>
#include <sstream>
#include <chrono>
#include <thread>
#include <unordered_set>

struct Tree {
    std::string species;
    std::string age;
    std::string quantity;
};

std::vector<Tree> trees;
std::unordered_map<std::string, Tree> treeHashMap;

void addTree(const Tree& tree) {
    trees.push_back(tree);
    treeHashMap[tree.species] = tree;
}

void registration() {
    std::string species, age, quantity;
    std::cout << "Enter Species: ";
    std::cin >> species;
    std::cout << "Enter Age: ";
    std::cin >> age;
    std::cout << "Enter Quantity: ";
    std::cin >> quantity;
    Tree newTree{ species, age, quantity };
    addTree(newTree);
}

void saveTreesToFile() {
    std::string filename = "treeinfo.bat";
    std::ofstream file(filename, std::ios::out | std::ios::trunc);

    if (file.is_open()) {
        file << "@echo off\n";
        file << "echo Tree Information:\n";
        for (const Tree& tree : trees) {
            file << "echo " << tree.species << "," << tree.age << "," << tree.quantity << "\n";
        }
        file.close();
        std::cout << "Tree information has been saved to " << filename << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
    else {
        std::cout << "Failed to open the file for saving." << std::endl;
    }
}


void loadTreesFromFile() {
    std::string filename = "treeinfo.txt";
    std::ifstream file(filename);

    if (file.is_open()) {
        trees.clear(); // Önceki verileri temizle

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream linestream(line);
            std::string species, age, quantity;

            std::getline(linestream, species, ',');
            std::getline(linestream, age, ',');
            std::getline(linestream, quantity, ',');

            trees.push_back({ species, age, quantity });
        }
        file.close();
        std::cout << "Members have been loaded from " << filename << std::endl;
    }
    else {
        std::cout << "Failed to open the file for loading." << std::endl;
    }
}



/*void updateTrees() {
    loadTreesFromFile(); // Mevcut verileri yükle

    int index = 0;
    for (const Tree& tree : trees) {
        std::string species, age, quantity;

        // Kullanıcıdan yeni verileri al
        std::cout << "Enter new species for tree " << index << ": ";
        std::cin >> species;
        std::cout << "Enter new age for tree " << index << ": ";
        std::cin >> age;
        std::cout << "Enter new quantity for tree " << index << ": ";
        std::cin >> quantity;

        // Verileri güncelle
        trees[index].species = species;
        trees[index].age = age;
        trees[index].quantity = quantity;

        ++index;
    }

    saveTreesToFile(); // Güncellenmiş verileri dosyaya kaydet
}
*/