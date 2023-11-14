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

using namespace std;


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
    system("cls");
    PrintCentered(" Forestry Management and Timber Products");
    PrintCentered("----------------------------------------");
    PrintCentered("|    1 - Tree Tracking                 |");
    PrintCentered("|    2 - Forest Management             |");
    PrintCentered("|    3 - Timber Sales And Shipment     |");
    PrintCentered("|    4 - Quit                          |");
    PrintCentered("----------------------------------------");
    PrintCentered("Selection: ");
    int choice;
    std::cin >> choice;
    system("cls");

    switch (choice) {
      case 1:
        while (true) {
          system("cls");
          PrintCentered("Tree Tracking");
          PrintCentered("----------------------------------------");
          PrintCentered("|        1 - Add Tree                   |");
          PrintCentered("|        2 - Edit Tree                  |");
          PrintCentered("|        3 - List Tree                  |");
          PrintCentered("|        4 - Main Menu                  |");
          PrintCentered("----------------------------------------");
          PrintCentered("Selection: ");
          int subChoice;
          std::cin >> subChoice;

          switch (subChoice) {
            case 1:
              system("cls");
              registration();
              saveTreesToFile();
              break;

            case 2:
              system("cls");
              updateTrees();
              break;

            case 3:
              break;

            case 4:
              break;

            case 5:
              system("cls");
              break;

            default:
              std::cout << "Invalid choice. Please try again." << std::endl;
          }

          if (subChoice == 5) {
            break;
          }
        }

        break;

      case 2:
        cout << "Forest Management selected!" << endl;
        // Forest Management fonksiyonunu çağırabilirsiniz.
        break;

      case 3:
        cout << "Timber Sales And Shipment selected!" << endl;
        // Timber Sales And Shipment fonksiyonunu çağırabilirsiniz.
        break;

      case 5:
        return 0;

      default:
        cout << "Invalid choice! Please try again." << endl;
    }
  }
}
