#include <iostream>
#include <chrono>
#include <thread>
#include "battle.h"
using namespace std;
#include "decisions.h"

void lvl6() {
    cout << "Hello" << endl;
}
void lvl4() {};
void lvl2() {
    int decision;
	cout << "While traveling North, you can hear the breeze of the winds rushing throught the trees,but between the gust of the winds you can hear a cry for help." << endl;
	cout << "Will you:" << endl;
	cout << "1: Answer the cry for help off the beaten path" << endl;
	cout << "2: Ignore the cries and continue on Northward" << endl;
    cin >> decision;
    while (true) {

        if (decision == 1) {
            cout << "" << endl;
            cout << "Leaving the path, the cries begin to become louder and louder. In view lies a goblin with their leg trapped within a bear trap!!" << endl;
            cout << "He spots you and says 'Please HElP!'. You agree and walk over and pry open the snare" << endl;
            cout << " Once the snare is opened, He springs at you and attacks!! You must fight.." << endl;
            cout << "" << endl;
            goblin();

            break; // Exit the loop
        }
        else if (decision == 2) {
            // Option 2
            lvl4();
            break; // Exit the loop
        }
        else {
            cout << "I'm sorry I dont know how to do choice " << decision << " Please choose 1 or 2." << endl;
            cout << "Pick between Choice 1 or 2" << endl;
            cin >> decision;
        }
    }


}
void lvl3() {

}

void lvl5() {

}

void lvl7() {

}
void lvl8() {
}
void lvl9() {
}
void lvl10() {
}
void lvl11() {
};