/*----------------------------------------------
 * Program 2: Cuatro
 *
 * Class: CS 141, Spring 2020. Tue 4pm lab
 * System: CLion on Windows 10
 * Author: Shawn Klein
 *
 * ---------------------------------------------
 */
#include <iostream>
#include <map>

using namespace std;

void displayBoard(basic_string<char> *board) {

    cout << "       ---------    Square #" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << "      | "
             << board[i*4 + 0] << " "
             << board[i*4 + 1] << " "
             << board[i*4 + 2] << " "
             << board[i*4 + 3] << " |  "
             << i*4 + 1 << "  " << i*4 + 2 << "  "
             << i*4 + 3 << "  " << i*4 + 4 << endl;
    }
    cout << "       ---------"<< endl;

    cout << "      Pieces:     Curved Straight"<< endl;
    cout << "            Upper: OO/CC  II/ZZ"<< endl;
    cout << "            Lower: oo/cc  ii/zz"<< endl;
    cout << "                Vowel/Consonant"<< endl;
}

int main() {
    bool activeGame = true;
    string userToken;
    int userPosition;
    string board[16] = {".",".",".",".",".",".",".",".",".",".",".",".",".",".",".","."};
    map<char, char> availableTokens = {
            { 'O', 'O' },
            { 'C', 'C' },
            { 'o', 'o' }
    };
    cout << "Welcome to the game of Cuatro!" << endl;

    while (activeGame) {
        displayBoard(board);

        cout << "Enter destination: ";
        cin >> userToken;
        cin >> userPosition;
        if (userToken == "q") {
            activeGame = false;
        }

        board[userPosition] = userToken;
    }

    return 0;
}







//cout << "      | . . . . |  1  2  3  4"<< endl; // 0 *4  +1 +2 +3 +4
//cout << "      | . . . . |  5  6  7  8"<< endl; // 1 *4
//cout << "      | . . . . |  9 10 11 12"<< endl; // 2 *4
//cout << "      | . . . . | 13 14 15 16"<< endl; // 3