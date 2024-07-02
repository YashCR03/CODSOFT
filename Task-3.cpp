#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE];
char currentPlayer;

void initializeBoard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << "\n";
        if (i < SIZE - 1) cout << "--+---+--\n";
    }
    cout << "\n";
}

bool isValidMove(int row, int col) {
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ';
}

void makeMove(int row, int col) {
    if (isValidMove(row, col)) {
        board[row][col] = currentPlayer;
    } else {
        cout << "Invalid move! Try again.\n";
    }
}

bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }
    return false;
}

bool checkDraw() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void playGame() {
    initializeBoard();
    currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;

    while (!gameWon && !gameDraw) {
        displayBoard();
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        while (!(cin >> row >> col)) {
            cout << "Invalid input. Please enter numbers for row and column: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        row--; // Adjust for 0-based index
        col--; // Adjust for 0-based index
        if (isValidMove(row, col)) {
            makeMove(row, col);
            gameWon = checkWin();
            if (!gameWon) {
                gameDraw = checkDraw();
                if (!gameDraw) {
                    switchPlayer();
                }
            }
        } else {
            cout << "Invalid move! Cell already occupied or out of bounds. Try again.\n";
        }
    }

    displayBoard();
    if (gameWon) {
        cout << "Congratulations! Player " << currentPlayer << " wins!\n";
    } else if (gameDraw) {
        cout << "The game is a draw!\n";
    }
}

int main() {
    char playAgain;
    do {
        playGame();
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "Thanks for playing! Goodbye!\n";
    return 0;
}
