#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <queue>
#include <fstream>
#include <sstream>
#include "../../forestry/header/forestry.h"
#include "../../forestry/src/forestry.cpp"
#include "forestry.h"
#include <limits>
using namespace std;

// Ekranı temizle
void ClearScreen() {
  cout << "\033[2J\033[H";  // Unix/Linux ve MacOS için
  // system("cls");  // Windows için
}


void PrintCentered(const std::string &text, int screenWidth = 80) {
  // Metni ortalamak için kullanılacak boşluk sayısını hesapla
  int padding = (screenWidth - text.length()) / 2;

  // Eğer metin uzunluğu ekran genişliğinden büyükse veya eşitse hata durumu yazdır
  if (padding < 0) {
    std::cerr << "Error: Text length exceeds or equals screen width." << std::endl;
    // Hata durumunda fonksiyonu terk et
    return;
  }

  // Boşlukları metnin etrafına yerleştirerek metni ortala ve yazdır
  std::cout << std::string(padding, ' ') << text << std::string(padding, ' ') << std::endl;
}

int main() {
  while (true) {
    ClearScreen();
    PrintCentered(" Forestry Management and Timber Products");
    PrintCentered("----------------------------------------");
    PrintCentered("|    1 - Add                           |");
    PrintCentered("|    2 - Edit                          |");
    PrintCentered("|    3 - Delete                        |");
    PrintCentered("|    4 - List                          |");
    PrintCentered("|    5 - Quit                          |");
    PrintCentered("----------------------------------------");
    PrintCentered("Selection: ");
    int choice;
    std::cin >> choice;

    switch (choice) {
      case 1:
        registration();
        enterForMenu();
        break;

      case 2:
        updateTrees();
        enterForMenu();
        break;

      case 3:
        deleteTree();
        enterForMenu();
        break;

      case 4:
        listTreesFromFile();
        enterForMenu();
        break;

      case 5:
        return 0;

      default:
        std::cout << "Invalid choice! Please try again." << std::endl;
        enterForMenu();
    }
  }

  return 0;
}
