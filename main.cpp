/*----------------------------------------------------------
 * Program 2: Cuatro
 *
 * Class: CS 141, Spring 2020. Tue 4pm lab
 * System: CLion on Windows 10 & CLion on Mac
 * Author: Shawn Klein
 *
 * NOTE: To the users browsing my repo, this
 * project was built following the constraints
 * listed below:
 * 2) The board must be displayed and manipulated
 * by using 16 separate variables representing the
 * 16 locations on the board.
 * 3) You may store potential characters remaining
 * to be played ("OO/CC  II/ZZ" and "oo/cc  ii/zz")
 * in one or more C++ strings.
 * 4) You may not use arrays or vectors or C++ string
 * variables anywhere in your program besides what
 * has been specifically described above.
 * ---------------------------------------------------------
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

void assignToBoard(char c, int i) {
    switch (i-48) {
        case  1: b1  = c; break;
        case  2: b2  = c; break;
        case  3: b3  = c; break;
        case  4: b4  = c; break;
        case  5: b5  = c; break;
        case  6: b6  = c; break;
        case  7: b7  = c; break;
        case  8: b8  = c; break;
        case  9: b9  = c; break;
        case 10: b10 = c; break;
        case 11: b11 = c; break;
        case 12: b12 = c; break;
        case 13: b13 = c; break;
        case 14: b14 = c; break;
        case 15: b15 = c; break;
        case 16: b16 = c; break;
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
        default: return false;
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
        activeGame = false;
    }

    if (strIsFound(a) && strIsFound(b) && strIsFound(c) && strIsFound(d)){
        activeGame = false;
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

bool emptyTokens() {
    int stringVal;
    string blankStr =  "                ";
    for (int i = 0; i < avlTkns.size(); ++i) {
        stringVal += avlTkns.at(i);
    }
    cout << "STRING VALUE: " << stringVal << endl;
    return stringVal == 558;
}

int main() {
    bool activeGame = true;
    char userToken;
    char userPosition;
    int idx;
    int turnNum = 1;

    cout << "Welcome to the game of Cuatro!" << endl;

    while (activeGame) {
        displayBoard();

        cout << turnNum << ". Player " << (turnNum % 2 ? "1" : "2")
             << " enter piece, and Player "<< (turnNum % 2 ? "2" : "1")
             << " enter destination: ";

        cin >> userToken;
        cin >> userPosition;
        cout << endl;

        if ((isPositionAvailable(userPosition)) == 1) {
            idx = avlTkns.find(userToken);
            if (idx > -1 ){
                turnNum++;
                avlTkns.replace(idx ,1," ");
                assignToBoard(userToken, userPosition);
                checkForWin();
            } else {
                cout << "*** Sorry, that is an invalid piece.  Please retry." << endl;
            }
        } else {
            cout << "*** Sorry, that destination is occupied.  Please retry." << endl;
        }

        cout << "empty tokesns returns: " << emptyTokens() << endl;
        if (userToken == 'q' || emptyTokens() == 1) {
            //cout << "TEST 16 SPACES: " << (avlTkns > 512) << endl;

            activeGame = false;
        }

    }

    return 0;
}




