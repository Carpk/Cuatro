/*----------------------------------------------
 * Program 2: Cuatro
 *
 * Class: CS 141, Spring 2020. Tue 4pm lab
 * System: CLion on Windows 10
 * Author: Shawn Klein
 *
 *
 * ---------------------------------------------
 */
#include <iostream>
using namespace std;

void displayBoard() {
    cout << "       ---------    Square #" << endl;
    cout << "      | . . . . |  1  2  3  4"<< endl;
    cout << "      | . . . . |  5  6  7  8"<< endl;
    cout << "      | . . . . |  9 10 11 12"<< endl;
    cout << "      | . . . . | 13 14 15 16"<< endl;
    cout << "       ---------"<< endl;
    cout << "      Pieces:     Curved Straight"<< endl;
    cout << "            Upper: OO/ C  II/ZZ"<< endl;
    cout << "            Lower: oo/cc  ii/zz"<< endl;
    cout << "                Vowel/Consonant"<< endl;
}

int main() {
    bool gameRunning = true;
    cout << "Welcome to the game of Cuatro!" << endl;

    while (gameRunning) {
        displayBoard();
        gameRunning = false;
    }

    return 0;
}



