// Adrian Frimpong
// CSC 240-0C1
// Fall 2026
// Tic-Tac-Toe Implementation file

#include "ticTacToe.h"
#include <iomanip>
#include <iostream>
#include <random>

using namespace std;

// The invariant of the board during play, in one
// sentence — after pass i, the tic tac toe board is evaluated against
// the winning line configs. Only if there is no winner or draw does another
// move continue.
void ticTacToe::play() {
    srand(time(0)); // set the random seed based on time.
    bool done = false;
    char player;
    if (rand() % 2 == 0) {
        player = 'X';
    } else {
        player = 'O';
    }
    displayBoard();

    // tournament loop here before while !done.
    bool keepPlaying = true;
    while (keepPlaying) {
        while (!done) {
            done = getXOMove(player);

            if (player == 'X')
                player = 'O';
            else
                player = 'X';
        }

        cout << "\n\nWant to keep playing? y/n" << endl;
        char resp;
        bool responseValid = false;
        cin.clear();
        cin.ignore(1000, '\n');
        while (!(cin >> resp) && !responseValid) {
            if (resp != 'y' || resp != 'n') {
                cout << "Invalid response. Please enter 'y' or 'n'" << endl;
                cout << "\n\nWant to keep playing? y/n" << endl;
            } else {
                responseValid = true;
            }
        }

        if (resp == 'n') {
            keepPlaying = false;
            cout << "********************" << endl;
            cout << "---- Game Tally ----" << endl;
            cout << "Player x: " << playerXScore << endl;
            cout << "Player o: " << playerOScore << endl;
            cout << "********************" << endl;
        }
    }
}

void ticTacToe::displayBoard() const {
    cout << endl
         << setw(3) << "" << setw(4) << "1" << setw(4) << "2" << setw(4) << "3"
         << endl;
    for (int rowIndex = 0; rowIndex <= 3; rowIndex++) {
        cout << setw(4) << "" << "+---+---+---+" << endl;
        // print board row
        if (rowIndex < 3) {
            cout << setw(3) << rowIndex + 1 << " | " << board[rowIndex][0]
                 << " | " << board[rowIndex][1] << " | " << board[rowIndex][2]
                 << " |" << endl;
        }
    }
}

bool ticTacToe::isValidMove(int row, int col) const {
    int gridRow = row - 1, gridCol = col - 1;
    bool valid = false;
    // valid grid row/col checks
    if (!(gridRow < 0 || gridRow > 2 || gridCol < 0 || gridCol > 2)) {
        if (board[gridRow][gridCol] != ' ') {
            cout << "That square is already taken, try again";
            valid = false;
        } else {
            valid = true;
        }
    }
    return valid;
}

/* initialize selection to invalid moves to prompt user for move
1. Get player move
 a. if move is valid, add to game state
 b. else we ask again
2. call game status
 a. if over - display win/draw and return true
 b. return false
*/
bool ticTacToe::getXOMove(char playerSymbol) {
    int row = -1, col = -1;
    status currentStatus;
    while (!isValidMove(row, col)) {
        cout << "\n\nPlayer " << playerSymbol << " enter move: ";
        while (!(cin >> row >> col)) {
            cout << "Invalid move. Try again" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    // valid move - populate in game
    board[row - 1][col - 1] = playerSymbol;

    // display new board state
    displayBoard();

    currentStatus = gameStatus();

    if (currentStatus == CONTINUE) {
        return false;
    }
    if (currentStatus == WIN) {
        cout << "Player " << playerSymbol << " wins!" << endl;
        if (playerSymbol == 'X') {
            playerXScore += 1;
        } else {
            playerOScore += 1;
        }
    } else if (currentStatus == DRAW) {
        cout << "The game is a draw";
    }
    return true;
}

// winning line struct to hold starting point and row/col deltas to
// increment through.
struct LineConfig {
    int startRow;
    int startCol;
    int deltaRow;
    int deltaCol;
};

const LineConfig winLines[8] = {
    // 3 Rows: Start at column 0, move right (deltaCol = 1)
    {0, 0, 0, 1},
    {1, 0, 0, 1},
    {2, 0, 0, 1},

    // 3 Columns: Start at row 0, move down (deltaRow = 1)
    {0, 0, 1, 0},
    {0, 1, 1, 0},
    {0, 2, 1, 0},

    // 2 Diagonals
    {0, 0, 1, 1}, // Top-left to bottom-right (move down and right)
    {0, 2, 1, -1} // Top-right to bottom-left (move down and left)
};
status ticTacToe::gameStatus() {
    noOfMoves++;
    for (auto lineConfig : winLines) {
        // check for empty spaces in winning line and continue if unfilled
        char winningSym = board[lineConfig.startRow][lineConfig.startCol];
        if (winningSym == ' ')
            continue;
        for (int i = 0; i < 3; i++) {
            int currRow = lineConfig.startRow + (i * lineConfig.deltaRow),
                currCol = lineConfig.startCol + (i * lineConfig.deltaCol);
            if (board[currRow][currCol] != winningSym)
                break;
            else if (i == 2) {
                // winner winner chicken dinner
                return WIN;
            }
        }
    }
    if (noOfMoves != 9)
        return CONTINUE;
    else
        return DRAW;
}

void ticTacToe::reStart() {
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            board[row][col] = ' ';

    noOfMoves = 0;
}

ticTacToe::ticTacToe() {
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            board[row][col] = ' ';

    noOfMoves = 0;
}
