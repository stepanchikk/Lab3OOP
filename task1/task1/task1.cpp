#include <iostream>
#include <vector>

class TicTacToe {
private:
    char board[3][3];
    char activePlayer;
    bool gameOver;

public:
    TicTacToe() {
        resetBoard();
    }

    void resetBoard() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = ' ';
            }
        }
        activePlayer = 'X';
        gameOver = false;
    }

    void displayBoard() {
        std::cout << "\n";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << " " << board[i][j] << " ";
                if (j < 2) std::cout << "|";
            }
            std::cout << "\n";
            if (i < 2) std::cout << "---+---+---\n";
        }
        std::cout << "\n";
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ' || gameOver) {
            std::cout << "Invalid move. Try again.\n";
            return false;
        }
        board[row][col] = activePlayer;
        if (checkWin()) {
            displayBoard();
            std::cout << "Player " << activePlayer << " wins!\n";
            gameOver = true;
        }
        else if (checkDraw()) {
            displayBoard();
            std::cout << "It's a draw!\n";
            gameOver = true;
        }
        else {
            switchPlayer();
        }
        return true;
    }

    bool checkWin() {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == activePlayer && board[i][1] == activePlayer && board[i][2] == activePlayer) return true;
            if (board[0][i] == activePlayer && board[1][i] == activePlayer && board[2][i] == activePlayer) return true;
        }
        if (board[0][0] == activePlayer && board[1][1] == activePlayer && board[2][2] == activePlayer) return true;
        if (board[0][2] == activePlayer && board[1][1] == activePlayer && board[2][0] == activePlayer) return true;
        return false;
    }

    bool checkDraw() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') return false;
            }
        }
        return true;
    }

    void switchPlayer() {
        activePlayer = (activePlayer == 'X') ? 'O' : 'X';
    }

    void playGame() {
        resetBoard();
        int row, col;
        while (!gameOver) {
            displayBoard();
            std::cout << "Player " << activePlayer << ", enter row and column (0-2): ";
            std::cin >> row >> col;
            makeMove(row, col);
        }
    }
};

int main() {
    TicTacToe game;
    char choice;
    do {
        game.playGame();
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    return 0;
}
