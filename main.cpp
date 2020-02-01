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
#include <string>

using namespace std;

// these are my global variables
char b1 = '.',  b2 = '.',  b3 = '.',  b4 = '.',  b5 = '.',  b6 = '.',  b7 = '.',  b8 = '.';
char b9 = '.', b10 = '.', b11 = '.', b12 = '.', b13 = '.', b14 = '.', b15 = '.', b16 = '.';
string t = "OOCCIIZZoocciizz";
bool activeGame = true;

void displayBoard() {

    cout << "       ---------    Square #\n      | "
         << b1  << ' ' << b2  << ' ' << b3  << ' ' << b4  << " |  1  2  3  4\n      | "
         << b5  << ' ' << b6  << ' ' << b7  << ' ' << b8  << " |  5  6  7  8\n      | "
         << b9  << ' ' << b10 << ' ' << b11 << ' ' << b12 << " |  9 10 11 12\n      | "
         << b13 << ' ' << b14 << ' ' << b15 << ' ' << b16 << " | 13 14 15 16" << endl;
    cout << "       ---------\n      Pieces:     Curved Straight"<< endl;
    cout << "            Upper: " << t.at(0) << t.at(1) << "/" << t.at(2) << t.at(3)
         << "  " << t.at(4) << t.at(5) << "/" << t.at(6) << t.at(7) << endl;
    cout << "            Lower: " << t.at(8) << t.at(9) << "/" << t.at(10) << t.at(11)
         << "  " << t.at(12) << t.at(13) << "/" << t.at(14) << t.at(15) << endl;
    cout << "                Vowel/Consonant"<< endl;
}

void isTokenAvailable (char t) {

    for (int i=1; i <= 16; ++i) {
        //optional<char> 'b' + to_string(i);
        //if (input == 'b' + to_string(i)) {
        //    b + i -> variable
        //}
        //create(false).value_or("empty")
    }
}

void isPositionAvailable() {
    //cout << "Value is: " << n << endl;
}

bool curIsFound(char c) {
    const string curlies = "oOcC";
    return curlies.find(c) != string::npos;
}

bool strIsFound(char c) {
    const string straights = "iIzZ";
    return straights.find(c) != string::npos;
}

void checkCombo(char a,char b,char c,char d) {
    if (curIsFound(a) && curIsFound(b) && curIsFound(c) && curIsFound(d)){
        cout << "FOUND CURLY COMBO" << endl;
    }
    if (strIsFound(a) && strIsFound(b) && strIsFound(c) && strIsFound(d)){
        cout << "FOUND STRAIGHT COMBO" << endl;
    }
}


void checkForWin() {
    // check quadrants
    checkCombo( b1, b2, b5, b6);
    checkCombo( b3, b4, b7, b8);
    checkCombo( b9,b10,b13,b14);
    checkCombo(b11,b12,b15,b16);

    // check rows
    checkCombo( b1, b2, b3, b4);
    checkCombo( b5, b6, b7, b8);
    checkCombo( b9,b10,b11,b12);
    checkCombo(b13,b14,b15,b16);

    // check columns
    checkCombo(b1,b5,b9,b13);
    checkCombo(b2,b6,b10,b14);
    checkCombo(b3,b7,b11,b15);
    checkCombo(b4,b8,b12,b16);

    // check cross
    checkCombo(b1,b6,b11,b16);
    checkCombo(b4,b7,b10,b13);
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
                //b1+b2+b3+b4

                //cout << "compare: " << (curlies.compare(reinterpret_cast<const char *>('o' + 'c' + 'O' + 'C')) > 0) << endl;
                checkCombo('z' ,'z' ,'z' ,'z');
            } else {
                cout << "BAD TOKEN!" << endl;
            }
        } else {
            cout << "Position full, try again" << endl;
        }
        //displayBoard();
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

