#include <iostream>
#include <vector>
using namespace std;

// Function to display the board
void displayBoard(const vector<vector<char>>& board) {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        cout << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n-----------\n";
    }
    cout << "\n";
}

// Function to check win
bool checkWin(const vector<vector<char>>& board, char player) {
    // Rows, Columns and Diagonals
    for (int i = 0; i < 3; ++i)
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

// Function to check draw
bool checkDraw(const vector<vector<char>>& board) {
    for (auto& row : board)
        for (char cell : row)
            if (cell == ' ')
                return false;
    return true;
}

// Function to switch players
char switchPlayer(char currentPlayer) {
    return (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to play the game
void playGame() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    int row, col;

    while (true) {
        displayBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (row and column: 1-3 1-3): ";
        cin >> row >> col;

        // Validate input
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' ') {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        board[row-1][col-1] = currentPlayer;

        // Check win
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "🎉 Player " << currentPlayer << " wins!\n";
            break;
        }

        // Check draw
        if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!\n";
            break;
        }

        // Switch turn
        currentPlayer = switchPlayer(currentPlayer);
    }
}

int main() {
    char playAgain;

    do {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thank you for playing!\n";
    return 0;
}
