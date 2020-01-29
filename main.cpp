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


void displayBoard(map<string, char> m, string t) {

    cout << "       ---------    Square #\n      | "
         << m.at("b1") << ' ' << m.at("b2") << ' ' << m.at("b3")
         << ' ' << m.at("b4") << " |  1  2  3  4\n      | "
         << m.at("b5") << ' ' << m.at("b6") << ' ' << m.at("b7")
         << " . |  5  6  7  8" << endl;
    cout << "      | . . . . |  9 10 11 12" << endl;
    cout << "      | . . . . | 13 14 15 16" << endl;
    cout << "       ---------" << endl;
    cout << "      Pieces:     Curved Straight"<< endl;
    cout << "            Upper: " << t.at(0) << t.at(1) << "/" << t.at(2) << t.at(3)
         << "  " << t.at(4) << t.at(5) << "/" << t.at(6) << t.at(7) << endl;
    cout << "            Lower: oo/cc  ii/zz"<< endl;
    cout << "                Vowel/Consonant"<< endl;
}

int main() {
    bool activeGame = true;
    char userToken;
    string userPosition;
    string tokens = "OOCCIIZZoocciizz";

    map<string, char> m{{ "b1", '.'},{ "b2", '.'},{ "b3", '.'},{ "b4", '.'},
                        { "b5", '.'},{ "b6", '.'},{ "b7", '.'},{ "b8", '.'},
                        { "b9", '.'},{"b10", '.'},{"b11", '.'},{"b12", '.'},
                        {"b13", '.'},{"b14", '.'},{"b15", '.'},{"b16", '.'}};

    cout << "Welcome to the game of Cuatro!" << endl;

    while (activeGame) {
        displayBoard(m, tokens);

        cout << "Enter destination: ";
        //cin >> userToken;
        //cin >> userPosition;
        userToken = 'I';
        userPosition = "5";

        if (m.at("b" + userPosition) == '.') {
            int i = tokens.find(userToken);
            cout << "tokens found: " << i << endl;
            if (i > -1 ){
                cout << "SUCCESSFUL TOKEN!" << endl;
                tokens.replace(i,1," ");
                m["b"+userPosition] = userToken;
            } else {
                cout << "BAD TOKEN!" << endl;
            }
        } else {
            cout << "Position full, try again" << endl;
        }
        displayBoard(m, tokens);
        if (userToken == 'q' || true || tokens == "                ") {
            int hexVal;
            //stringstream strm;
            //strm << "                ";
            //strm >> hex >> hexVal;
            //stoi(s, 0, 16)
            cout << "HEX: " << strtol("                ", 0, 16) << endl;
            activeGame = false;
        }

    }

    return 0;
}










//char b1 = '.', b2 = '.', b3 = '.', b4 = '.', b5 = '.', b6 = '.', b7 = '.', b8 = '.';
//char b9 = ".", b10 = ".", b11 = ".", b12 = ".", b13 = ".", b14 = ".", b15 = ".", b16 = ".";


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

