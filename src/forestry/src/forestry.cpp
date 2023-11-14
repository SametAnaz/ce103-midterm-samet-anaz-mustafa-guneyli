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


    class Tree {
    public:
        Tree() : species(""), age(""), quantity("") {}

        Tree(const std::string& species, const std::string& age, const std::string& quantity)
            : species(species), age(age), quantity(quantity) {}

        std::string getSpecies() const {
            return species;
        }

        std::string getAge() const {
            return age;
        }

        std::string getQuantity() const {
            return quantity;
        }

    private:
        std::string species;
        std::string age;
        std::string quantity;
    };


    class ForestManager {
    public:
        void addTree(const Tree& tree) {
            trees.push_back(tree);
            treeHashMap[tree.getSpecies()] = tree;
        }

        void registration() {
            std::string species, age, quantity;
            std::cout << "Enter Species: ";
            std::cin >> species;
            std::cout << "Enter Age: ";
            std::cin >> age;
            std::cout << "Enter Quantity: ";
            std::cin >> quantity;
            Tree newTree(species, age, quantity);
            addTree(newTree);
        }



        void saveTreesToFile() {
            std::string filename = "treeinfo.txt"; 
            std::ofstream file(filename);
            system("cls");

            if (file.is_open()) {
                for (const Tree& tree : trees) {
                    file << tree.getSpecies() << "," << tree.getAge() << "," << tree.getQuantity() << "\n";
                }
                file.close();
                std::cout << "Members have been saved to " << filename << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                system("cls");

            }
            else {
                std::cout << "Failed to open the file for saving." << std::endl;
            }
        }
    




    private:
        std::vector<Tree> trees;
        std::unordered_map<std::string, Tree> treeHashMap;
};



    
    


