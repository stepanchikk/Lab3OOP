#include <iostream> // Для введення/виведення в консоль


class TicTacToe { //оголошення полів
private:
    char board[3][3]; // Ігрове поле розміром 3x3
    char activePlayer; // Поточний гравець ('X' або 'O')
    bool gameOver; // Статус гри: true, якщо гра завершена, false, якщо триває

public: //Конструктор класу
    TicTacToe() {
        resetBoard(); // Викликає метод для ініціалізації поля і початку гри
    }

    void resetBoard() { //скидання ігрової дошки
        for (int i = 0; i < 3; ++i) { // Проходимо по всіх рядках дошки
            for (int j = 0; j < 3; ++j) { // Проходимо по всіх стовпцях
                board[i][j] = ' '; // Заповнюємо поле пробілами
            }
        }
        activePlayer = 'X'; // Заповнюємо поле пробілами
        gameOver = false;  // Гра ще не закінчена
    }

    void displayBoard() { //виведення ігрового поля
        std::cout << "\n"; // Додаємо порожній рядок перед виведенням поля
        for (int i = 0; i < 3; ++i) { // Проходимо по всіх рядках
            for (int j = 0; j < 3; ++j) { // Проходимо по всіх стовпцях
                std::cout << " " << board[i][j] << " "; // Виводимо елемент поля з пробілами
                if (j < 2) std::cout << "|";  // Якщо це не останній стовпець, додаємо вертикальний розділювач
            }
            std::cout << "\n";
            if (i < 2) std::cout << "---+---+---\n"; // Якщо це не останній рядок, додаємо горизонтальні розділювачі
        }
        std::cout << "\n"; // Перехід на новий рядок після кожного рядка
    }

    bool makeMove(int row, int col) { //виконання ходу
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ' || gameOver) {
            std::cout << "Invalid move. Try again.\n";
            return false; // Якщо хід некоректний, просимо гравця повторити
        }
        board[row][col] = activePlayer; // Записуємо хід
        if (checkWin()) { //Перевірка перемоги
            displayBoard();
            std::cout << "Player " << activePlayer << " wins!\n";
            gameOver = true; // Якщо перемога, гра завершується

        }
        else if (checkDraw()) { //Перевірка нічиєї
            displayBoard();
            std::cout << "It's a draw!\n";
            gameOver = true; 

        }
        else { // Перехід до наступного гравця
            switchPlayer();
        }
        return true; // Повертаємо true, якщо хід був зроблений
    }

    bool checkWin() { //перевірка виграшних комбінацій
        for (int i = 0; i < 3; ++i) { // Перевіряємо горизонтальні лінії
            if (board[i][0] == activePlayer && board[i][1] == activePlayer && board[i][2] == activePlayer) return true;
            if (board[0][i] == activePlayer && board[1][i] == activePlayer && board[2][i] == activePlayer) return true; // Перевіряємо горизонтальні лінії
        }
        if (board[0][0] == activePlayer && board[1][1] == activePlayer && board[2][2] == activePlayer) return true; // Перевірка на діагональ
        if (board[0][2] == activePlayer && board[1][1] == activePlayer && board[2][0] == activePlayer) return true; // Перевірка на іншу діагональ
        return false; // Якщо жодна з умов не виконана, перемоги немає
    }

    bool checkDraw() { //перевірка нічиєї
        for (int i = 0; i < 3; ++i) { // Перевірка всіх клітинок на порожні місця
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') return false; // Якщо є порожнє місце – гра триває
            }
        }
        return true; // Якщо порожніх місць немає, це нічия
    }

    void switchPlayer() { //зміна активного гравця
        activePlayer = (activePlayer == 'X') ? 'O' : 'X';
    }

    void playGame() { //головний цикл гри
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

int main() { //запуск гри
    TicTacToe game;
    char choice;
    do {
        game.playGame(); // Запуск гри
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    return 0;
}
