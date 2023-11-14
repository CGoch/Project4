#include<iostream>
#include<random>
#include <chrono>
#include <thread>

#include "decisions.h"
#include "inventory.h"

using namespace std;
//Choices

void lvl1() {
    int decision;

    cout << "You are a brave warrior that fought for the kingdom of Eldoria in the Battle of Everflame Pass. During the battle you were gravely wounded and died a heroic death. Luckly you were chosen by Zephyrion, for such a sacrifice and were resurrected in the Realm of the Lost. The Realm of the Lost being a land between the Land of the Living and the Land of the Dead where Zephyrion's chosen are brought to complete their final quest before entering the Land of the Dead." << endl;
    cout << "Your final quest begins here.... " << endl;
    cout << "" << endl;
    chrono::seconds waitTime(5);
    this_thread::sleep_for(waitTime);
    cout << "You wake up on the ferry boat of the dead greeted by the Ferryman. You adress the Ferryman but he does not answer back and you decide it is best to sit in silence. Once the ship reaches the shore the Ferryman opens a small chest with items within" << endl;
    //Calling Item Select
    item_select();
    cout << "" << endl;
    cout<<"After picking up your selected items, he points for you to exit the ship.You do so and two paths lie before you. " << endl;
    cout << "Will you head down the East path or continue striaght down the North path" << endl;
    cout << "Enter Your Choice" << endl;
    cout << "1: North" << endl;
    cout << "2: East" << endl;
    cin >> decision;

    while (true) {

        if (decision == 1) {
            // Option 1
            lvl2();
            break; // Exit the loop
        }
        else if (decision == 2) {
            // Option 2
            lvl3();
            break; // Exit the loop
        }
        else {
            cout << "I'm sorry I dont know how to do choice "<< decision << " Please choose 1 or 2." << endl;
            cout << "Pick between Choice 1 or 2" << endl;
            cin >> decision;
        }
    }


}

int main() {
    // Title Panel

    // Game Intructions

    // Choose Difficulity

    // Intro
    cout << "#######                                          #######                                         " << endl;
    cout << "#       #  ####  #    # ##### # #    #  ####     #         ##   #    # #####   ##    ####  #   #" << endl;
    cout << "#       # #    # #    #   #   # ##   # #    #    #        #  #  ##   #   #    #  #  #       # # " << endl;
    cout << "#####   # #      ######   #   # # #  # #         #####   #    # # #  #   #   #    #  ####    # " << endl;
    cout << "#       # #  ### #    #   #   # #  # # #  ###    #       ###### #  # #   #   ######      #   # " << endl;
    cout << "#       # #    # #    #   #   # #   ## #    #    #       #    # #   ##   #   #    # #    #   #  " << endl;
    cout << "#       #  ####  #    #   #   # #    #  ####     #       #    # #    #   #   #    #  ####    #" << endl;
    cout << "" << endl;
    cout << ",_._._._._._._._._|___________________________________________________________________________," << endl;
    cout << "|_|_|_|_|_|_|_|_|_|__________________________________________________________________________/" << endl;
    cout << "" << endl;
    lvl1();



    return 0;
}