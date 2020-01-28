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
char b1 = '.', b2 = '.', b3 = '.', b4 = '.', b5 = '.', b6 = '.', b7 = '.', b8 = '.';
//char b9 = ".", b10 = ".", b11 = ".", b12 = ".", b13 = ".", b14 = ".", b15 = ".", b16 = ".";

void displayBoard() {

    cout << "       ---------    Square #\n      | "
         << b1 << ' ' << b2 << ' ' << b3 << ' ' << b4 << " |  1  2  3  4"<< endl;
    cout << "      | . . . . |  5  6  7  8"<< endl;
    cout << "      | . . . . |  9 10 11 12"<< endl;
    cout << "      | . . . . | 13 14 15 16"<< endl;
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

    map<string, char> m{{"b1", '.'},{"b2", '.'},{"b3", '.'},{"b4", '.'},
                        {"b5", '.'},{"b6", '.'},{"b7", '.'},{"b8", '.'},
                        {"b9", '.'},{"b10", '.'},{"b11", '.'},{"b12", '.'},
                        {"b13", '.'},{"b14", '.'},{"b15", '.'},{"b16", '.'}};

    cout << "Welcome to the game of Cuatro!" << endl;

    while (activeGame) {
        displayBoard();
        string tokens = "OOCCIIZZoocciizz";

        //cout << m.at("b5") << endl;

        cout << "Enter destination: ";
        //cin >> userToken;
        //cin >> userPosition;
        string userToken = "I";
        string userPosition = "5";

        if (m.at("b" + userPosition) == '.') {
            int i = tokens.find(userToken);
            cout << "tokens found: " << i << endl;
            if (i > -1 ){
                cout << "SUCCESSFUL TOKEN!" << endl;
            } else {
                cout << "BAD TOKEN!" << endl;
            }
        } else {
            cout << "Position full, try again" << endl;
        }

        if (userToken == "q" || true) {
            activeGame = false;
        }


    }

    return 0;
}









//  string board[16] = {".",".",".",".",".",".",".",".",".",".",".",".",".",".",".","."};
/*
for (int i = 0; i < 4; ++i) {
cout << "      | "
<< board[i*4 + 0] << " "
<< board[i*4 + 1] << " "
<< board[i*4 + 2] << " "
<< board[i*4 + 3] << " |  "
<< i*4 + 1 << "  " << i*4 + 2 << "  "
<< i*4 + 3 << "  " << i*4 + 4 << endl;
}
*/

