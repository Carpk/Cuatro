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
//#include <optional>
#include <map>
#include <regex>

using namespace std;

// these are my global variables
char b1 = '.',  b2 = '.',  b3 = '.',  b4 = '.',  b5 = '.',  b6 = '.',  b7 = '.',  b8 = '.';
char b9 = '.', b10 = '.', b11 = '.', b12 = '.', b13 = '.', b14 = '.', b15 = '.', b16 = '.';
string t = "OOCCIIZZoocciizz";

void displayBoard() {

    cout << "       ---------    Square #\n      | "
         << b1  << ' ' << b2  << ' ' << b3  << ' ' << b4  << " |  1  2  3  4\n      | "
         << b5  << ' ' << b6  << ' ' << b7  << ' ' << b8  << " |  5  6  7  8\n      | "
         << b9  << ' ' << b10 << ' ' << b11 << ' ' << b12 << " |  9 10 11 12\n      | "
         << b13 << ' ' << b14 << ' ' << b15 << ' ' << b16 << " | 13 14 15 16" << endl;
    cout << "       ---------" << endl;
    cout << "      Pieces:     Curved Straight"<< endl;
    cout << "            Upper: " << t.at(0) << t.at(1) << "/" << t.at(2) << t.at(3)
         << "  " << t.at(4) << t.at(5) << "/" << t.at(6) << t.at(7) << endl;
    cout << "            Lower: oo/cc  ii/zz"<< endl;
    cout << "                Vowel/Consonant"<< endl;
}

void isTokenAvailable (char t) {

    for (int i=1; i <= 16; ++i) {
        optional<char> 'b' + to_string(i);
        if input == 'b' + to_string(i) {
            b + i -> variable
        }
        //create(false).value_or("empty")
    }
}

void isPositionAvailable(string &n) {
    cout << "Value is: " << n << endl;
}


int main() {
    bool activeGame = true;
    char userToken;
    string userPosition;

    cout << "Welcome to the game of Cuatro!" << endl;

    while (activeGame) {
        displayBoard();

        cout << "Enter destination: ";
        //cin >> userToken;
        //cin >> userPosition;
        userToken = 'I';
        userPosition = "5";

        isPositionAvailable();
        if (true) {
            int i = t.find(userToken);
            cout << "tokens found: " << i << endl;
            if (i > -1 ){
                cout << "SUCCESSFUL TOKEN!" << endl;
                t.replace(i,1," ");
                //m["b" + userPosition] = userToken;
            } else {
                cout << "BAD TOKEN!" << endl;
            }
        } else {
            cout << "Position full, try again" << endl;
        }
        displayBoard();
        if (userToken == 'q' || true || t == "                ") {
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


// " " is 32

/*
"................"

"cc.."
"OO.."
"...."
"...."

"c..."
".O.."
"..c."
"...o"
*/

/*
map<string, char> m{{ "b1", '.'},{ "b2", '.'},{ "b3", '.'},{ "b4", '.'},
                    { "b5", '.'},{ "b6", '.'},{ "b7", '.'},{ "b8", '.'},
                    { "b9", '.'},{"b10", '.'},{"b11", '.'},{"b12", '.'},
                    {"b13", '.'},{"b14", '.'},{"b15", '.'},{"b16", '.'}};
*/

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

