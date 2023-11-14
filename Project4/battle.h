#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <functional>
#include "decisions.h"

using namespace std;

class TurnBasedFightGame {
private:
    int playerHealth;
    int enemyHealth;
    int playerSkill;
    int enemySkill;

public:
    // Constructor to initialize game state
    TurnBasedFightGame(int playerSkill, int enemySkill, int playerHealth, int enemyHealth)
        : playerHealth(playerHealth), enemyHealth(enemyHealth), playerSkill(playerSkill), enemySkill(enemySkill) {
        // Seed the random number generator
        srand(time(0));
    }

    // Function to roll a 12-sided die and add player's skill
    int rollDie() {
        return rand() % 12 + 1 + playerSkill;
    }

    // Function to roll for luck
    bool rollForLuck(int luckThreshold) {
        int luckRoll = rand() % 12 + 1;
        return luckRoll < luckThreshold;
    }

    // Function to simulate a turn
    void runTurn() {
        int playerRoll = rollDie();
        int enemyRoll = rollDie();

        cout << "Player rolled: " << playerRoll << endl;
        cout << "Enemy rolled: " << enemyRoll << endl;

        // Prompt user to use luck
        char useLuck;
        cout << "Do you want to use luck? (y/n): ";
        cin >> useLuck;

        int luckThreshold = 7;

        // If the player chooses to use luck
        if (useLuck == 'y') {
            if (rollForLuck(luckThreshold)) {
                cout << "You are lucky! Damage reduced by 1." << endl;
                playerHealth += 1;  // Reduce damage by increasing player health
                cout << "Player is lucky!" << endl;
            }
            else {
                cout << "Player is not lucky." << endl;
            }
        }

        if (playerRoll > enemyRoll) {
            enemyHealth -= (useLuck == 'y' && rollForLuck(luckThreshold)) ? 1 : 2;

            if (useLuck == 'y' && rollForLuck(luckThreshold)) {
                cout << "Player deals 3 damage to the enemy!" << endl;
            }
            else {
                cout << "Player deals 2 damage to the enemy!" << endl;
            }
        }
        else if (playerRoll < enemyRoll) {
            playerHealth -= 2;
            cout << "Enemy deals 2 damage to the player!" << endl;
        }
        else {
            cout << "It's a tie! No damage dealt." << endl;
        }

        displayHealth();
    }

    // Function to display current health of the player and enemy
    void displayHealth() {
        cout << "Player Health: " << playerHealth << endl;
        cout << "Enemy Health: " << enemyHealth << endl;
        cout << "-------------------------" << endl;
    }

    // Function to check if the game is over
    bool isGameOver() {
        return playerHealth <= 0 || enemyHealth <= 0;
    }

    // Function to display the winner of the game
    void displayWinner() {
        if (playerHealth <= 0) {
            cout << "Game Over. Enemy wins!" << endl;
        }
        else {
            cout << "Congratulations! Player wins!" << endl;
        }
    }

    // Function to get the player's health (added for callback)
    int getPlayerHealth() const {
        return playerHealth;
    }
};

void runTurnBasedFightGame(int playerSkill, int enemySkill, int playerHealth, int enemyHealth, std::function<void()> onUserWinCallback) {
    TurnBasedFightGame game(playerSkill, enemySkill, playerHealth, enemyHealth);

    while (!game.isGameOver()) {
        game.runTurn();
    }

    game.displayWinner();

    if (game.getPlayerHealth() > 0) {
        // User has won, so call the callback function
        onUserWinCallback();
    }
}

void AnotherFunction_1() {
    // Code for the other function
    lvl6();
}

void goblin() {
    int playerSkill = 10;
    int playerHealth = 23;
    int enemySkill = 3;
    int enemyHealth = 8;

    // Define a lambda function to be called when the user wins
    auto onUserWinCallback = []() {
        // Call your other function here
        AnotherFunction_1();
        };

    runTurnBasedFightGame(playerSkill, enemySkill, playerHealth, enemyHealth, onUserWinCallback);
}