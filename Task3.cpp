#include <iostream>
using namespace std;
// Global variables for the board and the current player
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentPlayer = 'X';
// Function to display the game board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j];
            if (j < 2) cout << " |";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}
// Function to check for a win
bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

    return false;
}
// Function to check for a draw
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
        }
    }
    return true;
}
// Function to update the board with the player's move
bool updateBoard(int move) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}
// Function to switch players
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
// Function to reset the game board
void resetBoard() {
    char num = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = num++;
        }
    }
}
int main() {
    char playAgain;
    do {
        int move;
        bool gameWon = false, gameDraw = false;
        resetBoard();
        currentPlayer = 'X';
        cout << "Welcome to Tic-Tac-Toe!\n";
        while (!gameWon && !gameDraw) {
            displayBoard();
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;

            if (move < 1 || move > 9 || !updateBoard(move)) {
                cout << "Invalid move! Try again.\n";
                continue;
            }
            gameWon = checkWin();
            if (!gameWon) gameDraw = checkDraw();
            if (!gameWon && !gameDraw) switchPlayer();
        }
        displayBoard();
        if (gameWon)
            cout << "Player " << currentPlayer << " wins!\n";
        else if (gameDraw)
            cout << "It's a draw!\n";
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    cout << "Thank you for playing!\n";
    return 0;
}