/*----------------------------------------------
 * Program 2: Cuatro
 *
 * Class: CS 141, Spring 2020. Tue 4pm lab
 * System: CLion on Windows 10 & CLion on Mac
 * Author: Shawn Klein
 *
 * ---------------------------------------------
 */
#include <iostream>
#include <string>

using namespace std;

// these are my global variables
const string constCurlies = "oOcC";
const string constStraights = "iIzZ";

string avlTkns = "OOCCIIZZoocciizz";
bool activeGame = true;

char b1 = '.',  b2 = '.',  b3 = '.',  b4 = '.',  b5 = '.',  b6 = '.',  b7 = '.',  b8 = '.';
char b9 = '.', b10 = '.', b11 = '.', b12 = '.', b13 = '.', b14 = '.', b15 = '.', b16 = '.';



void displayBoard() {

    cout << "       ---------    Square #\n      | "
         << b1  << ' ' << b2  << ' ' << b3  << ' ' << b4  << " |  1  2  3  4\n      | "
         << b5  << ' ' << b6  << ' ' << b7  << ' ' << b8  << " |  5  6  7  8\n      | "
         << b9  << ' ' << b10 << ' ' << b11 << ' ' << b12 << " |  9 10 11 12\n      | "
         << b13 << ' ' << b14 << ' ' << b15 << ' ' << b16 << " | 13 14 15 16" << endl;
    cout << "       ---------\n      Pieces:     Curved Straight"<< endl;
    cout << "            Upper: " << avlTkns.at(0) << avlTkns.at(1) << "/" << avlTkns.at(2) << avlTkns.at(3)
         << "  " << avlTkns.at(4) << avlTkns.at(5) << "/" << avlTkns.at(6) << avlTkns.at(7) << endl;
    cout << "            Lower: " << avlTkns.at(8) << avlTkns.at(9) << "/" << avlTkns.at(10) << avlTkns.at(11)
         << "  " << avlTkns.at(12) << avlTkns.at(13) << "/" << avlTkns.at(14) << avlTkns.at(15) << endl;
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

bool isPositionAvailable(int i) {
    switch (i-48) {
        case  1: return b1  == '.' ? true : false;
        case  2: return b2  == '.' ? true : false;
        case  3: return b3  == '.' ? true : false;
        case  4: return b4  == '.' ? true : false;
        case  5: return b5  == '.' ? true : false;
        case  6: return b6  == '.' ? true : false;
        case  7: return b7  == '.' ? true : false;
        case  8: return b8  == '.' ? true : false;
        case  9: return b9  == '.' ? true : false;
        case 10: return b10 == '.' ? true : false;
        case 11: return b11 == '.' ? true : false;
        case 12: return b12 == '.' ? true : false;
        case 13: return b13 == '.' ? true : false;
        case 14: return b14 == '.' ? true : false;
        case 15: return b15 == '.' ? true : false;
        case 16: return b16 == '.' ? true : false;
    }
}

bool curIsFound(char c) {
    return constCurlies.find(c) != string::npos;
}

bool strIsFound(char c) {
    return constStraights.find(c) != string::npos;
}

void checkCombo(char a,char b,char c,char d) {
    if (curIsFound(a) && curIsFound(b) && curIsFound(c) && curIsFound(d)){
        cout << "FOUND CURLY COMBO" << endl;
        activeGame = false;
    }

    if (strIsFound(a) && strIsFound(b) && strIsFound(c) && strIsFound(d)){
        cout << "FOUND STRAIGHT COMBO" << endl;
        activeGame = false;
    }
}


void checkForWin() {
    // test function
    //checkCombo('z' ,'z' ,'z' ,'z'); // REMOVE ME

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
    char userPosition;
    int idx;

    cout << "Welcome to the game of Cuatro!" << endl;

    while (activeGame) {
        displayBoard();

        cout << "Enter destination: ";
        //cin >> userToken;
        //cin >> userPosition;
        userToken = 'I';
        userPosition = '1';

        if ((isPositionAvailable(userPosition)) == 1) {
            idx = avlTkns.find(userToken);
            if (idx > -1 ){
                cout << "SUCCESSFUL TOKEN!" << endl;
                avlTkns.replace(idx ,1," ");

                checkForWin();
            } else {
                cout << "BAD TOKEN!" << endl;
            }
        } else {
            cout << "Position full, try again" << endl;
        }
        //displayBoard();
        if (userToken == 'q' || true || avlTkns == "                ") {
            //cout << "TEST 16 SPACES: " << (avlTkns > 512) << endl;

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

