/*----------------------------------------------------------
 * Program 2: Cuatro
 *
 * Class: CS 141, Spring 2020. Tue 4pm lab
 * System: CLion on Windows 10 & CLion on Mac
 * Author: Shawn Klein
 *
 * NOTE: To the users browsing my repo, this project
 * was built following the constraints listed below:
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

// Global variables
char b1 = '.',  b2 = '.',  b3 = '.',  b4 = '.',  b5 = '.',  b6 = '.',  b7 = '.',  b8 = '.';
char b9 = '.', b10 = '.', b11 = '.', b12 = '.', b13 = '.', b14 = '.', b15 = '.', b16 = '.';

void displayInstructions() {
    cout << "Welcome to the game of Cuatro, where you try to complete a set      \n"
         << "of four pieces that are alike.  Players take turns making moves.    \n"
         << "On each move your OPPONENT chooses the piece, then YOU get to       \n"
         << "place it on the board.  If you create a set of four alike when      \n"
         << "you place your piece, then you win!       \n"
         << "\n"
         << "A set of four alike can be completed by using four all upper (or all\n"
         << "lower) case characters, four all vowels (or all consonants), or four\n"
         << "all curved (or all straight-lined). Curved letters are 'O' and 'C'\n"
         << "(upper or lower), and straight-line letters are 'I' and 'Z' (upper or\n"
         << "lower). Groups of four can be created in a row, column, diagonal, or\n"
         << "corner quadrant.\n"
         << "\n"
         << "When prompted for input you may also enter 'x' or 'X' to exit." << endl;
}

void displayBoard(string avlTkns) {
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

// Assigns token to board
void assignToBoard(char c, int i) {
    switch (i) {
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
        default: break;
    }
}

// Checks if space is available on board
bool isPositionAvailable(int i) {
    switch (i) {
        case  1: return b1  == '.';
        case  2: return b2  == '.';
        case  3: return b3  == '.';
        case  4: return b4  == '.';
        case  5: return b5  == '.';
        case  6: return b6  == '.';
        case  7: return b7  == '.';
        case  8: return b8  == '.';
        case  9: return b9  == '.';
        case 10: return b10 == '.';
        case 11: return b11 == '.';
        case 12: return b12 == '.';
        case 13: return b13 == '.';
        case 14: return b14 == '.';
        case 15: return b15 == '.';
        case 16: return b16 == '.';
        default: return false;
    }
}

// Each function checks for their respective win type
bool isCurl(char c) {
    const string constCurly = "oOcC";
    return constCurly.find(c) != string::npos;
}
bool isStrait(char c) {
    const string constStrait = "iIzZ";
    return constStrait.find(c) != string::npos;
}
bool isConst(char c) {
    const string constConsts = "cCzZ";
    return constConsts.find(c) != string::npos;
}
bool isVowel(char c) {
    const string constVowel = "oOiI";
    return constVowel.find(c) != string::npos;
}
bool isUpper(char c) {
    const string constUpper = "OCIZ";
    return constUpper.find(c) != string::npos;
}
bool isLower(char c) {
    const string constLower = "ociz";
    return constLower.find(c) != string::npos;
}

// Checks for win combinations
void checkCombo(char a,char b,char c,char d, bool& activeGame) {
    if (isCurl(a) && isCurl(b) && isCurl(c) && isCurl(d)){
        activeGame = false;
    } else if (isStrait(a) && isStrait(b) && isStrait(c) && isStrait(d)){
        activeGame = false;
    } else if (isConst(a) && isConst(b) && isConst(c) && isConst(d)){
        activeGame = false;
    } else if (isVowel(a) && isVowel(b) && isVowel(c) && isVowel(d)){
        activeGame = false;
    } else if (isUpper(a) && isUpper(b) && isUpper(c) && isUpper(d)){
        activeGame = false;
    } else if (isLower(a) && isLower(b) && isLower(c) && isLower(d)){
        activeGame = false;
    }
}

// Checks winning position
void checkForWin(bool& activeGame) {
    // check quadrants
    checkCombo( b1, b2, b5, b6, activeGame);
    checkCombo( b3, b4, b7, b8, activeGame);
    checkCombo( b9,b10,b13,b14, activeGame);
    checkCombo(b11,b12,b15,b16, activeGame);

    // check rows
    checkCombo( b1, b2, b3, b4, activeGame);
    checkCombo( b5, b6, b7, b8, activeGame);
    checkCombo( b9,b10,b11,b12, activeGame);
    checkCombo(b13,b14,b15,b16, activeGame);

    // check columns
    checkCombo(b1,b5,b9,b13, activeGame);
    checkCombo(b2,b6,b10,b14, activeGame);
    checkCombo(b3,b7,b11,b15, activeGame);
    checkCombo(b4,b8,b12,b16, activeGame);

    // check cross
    checkCombo(b1,b6,b11,b16, activeGame);
    checkCombo(b4,b7,b10,b13, activeGame);
}

// Checks to see if additional tokens are available
bool emptyTokens(string& availableTokens) {
    return availableTokens == "                " ;
}


int main() {
    char userToken;
    int userPosition;
    int idx;
    int turnNum = 1;
    bool activeGame = true;
    const string acceptableTokens = "oOcCiIzZ";
    string availableTokens = "OOCCIIZZoocciizz";

    displayInstructions();

    while (activeGame) {
        displayBoard(availableTokens);

        cout << turnNum << ". Player " << (turnNum % 2 ? "1" : "2")
             << " enter piece, and Player "<< (turnNum % 2 ? "2" : "1")
             << " enter destination: ";

        cin >> userToken;
        if (userToken == 'X' ||userToken == 'x') {
            cout << "Exiting program..."  << endl;
            break;
        }

        cin >> userPosition;

        if ((isPositionAvailable(userPosition)) == 1) {
            idx = availableTokens.find(userToken);
            if (idx > -1 ){
                turnNum++;
                availableTokens.replace(idx ,1," ");
                assignToBoard(userToken, userPosition);
                checkForWin(activeGame);
            } else {
                cout << "*** Sorry, that is an invalid piece.  Please retry." << endl;
            }
        } else {
             if (userPosition < 1 || userPosition > 16) {
                cout << "*** Sorry, that destination is invalid.  Please retry." << endl;
            } else if (!acceptableTokens.find(userToken)) {
                 cout << "*** Sorry, that is an invalid piece.  Please retry." << endl;
             } else {
                 cout << "*** Sorry, that destination is occupied.  Please retry." << endl;
            }
        }

        // Quietly exits game if no winners
        if (emptyTokens(availableTokens)) {
            displayBoard(availableTokens);
            break;
        }

        // Declares winner and exits game
        if (!activeGame) {
            displayBoard(availableTokens);
            cout << "*** Player " << (turnNum % 2 ? "1" : "2") << " you won!" << endl;
            break;
        }
    }
    return 0;
}
