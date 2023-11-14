#include <iostream>
#include <vector>
#include "inventory.h"
#include "decisions.h"
using namespace std;

void item_select() {
    std::vector<int> inventory = {};
    int item_number;
    //Prompt
    std::cout << "Pick 3 items to have on your journey" << std::endl;
    std::cout << "1:Potion of Plant Control" << std::endl;
    std::cout << "2:Brass Flute" << std::endl;
    std::cout << "3:Net of Entanglement" << std::endl;
    std::cout << "4:A small brass bell" << std::endl;
    std::cout << "5:Potion of Anti-Posion" << std::endl;

    //Loop for User to select 3 items
    for (int i = 0; i < 3; ++i) {
        std::cout << "Enter the item number you would like to pick: ";
        std::cin >> item_number;

        if (item_number == 1) {
            inventory.push_back(item_number);
        }
        if (item_number == 2) {
            inventory.push_back(item_number);
        }
        if (item_number == 3) {
            inventory.push_back(item_number);
        }
        if (item_number == 4) {
            inventory.push_back(item_number);
        }
        if (item_number == 5) {
            inventory.push_back(item_number);
        }
    }



//Item Checking System
//    int number_to_check = 2;
  //  for (auto item : inventory)
    //{
      //  if (item == 2)
        //{

        //}
        //else
        //{

        //}
    //}
}
