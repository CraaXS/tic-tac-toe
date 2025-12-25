#include <iostream>
#include <array>

// Konstanten definieren
const int BOARD_SIZE = 9;
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';

// Funktionen deklarieren
void printBoard(const std::array<char, BOARD_SIZE>& board);
bool makeMove(std::array<char, BOARD_SIZE>& board, int position, char player);
bool checkWin(const std::array<char, BOARD_SIZE>& board, char player);
bool checkDraw(const std::array<char, BOARD_SIZE>& board);
int getPlayerInput(char currentPlayer);

int main() {
    std::array<char, BOARD_SIZE> board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char currentPlayer = PLAYER_X;
    bool gameRunning = true;
    int moves = 0;

    while (gameRunning) {
        // 1. Spielfeld anzeigen
        printBoard(board);
        
        // 2. Spielereingabe
        std::cout << "Spieler " << currentPlayer << ", waehle ein Feld (1-9): ";
        int position;
        std::cin >> position;
        
        // 3. Zug prüfen und durchführen
        if (position < 1 || position > 9) {
            std::cout << "Ungueltige Eingabe!\n";
            continue;
        }
        
        if (!makeMove(board, position - 1, currentPlayer)) {
            std::cout << "Feld bereits belegt!\n";
            continue;
        }
        
        moves++;
        
        // 4. Gewinn prüfen
        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            std::cout << "Spieler " << currentPlayer << " gewinnt!\n";
            gameRunning = false;
        }
        // 5. Unentschieden prüfen
        else if (checkDraw(board)) {
            printBoard(board);
            std::cout << "Unentschieden!\n";
            gameRunning = false;
        }
        // 6. Spieler wechseln
        else {
            currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
        }
    }
    
    // Nach Spielende fragen, ob nochmal
    std::cout << "Noch eine Runde? (j/n): ";
    char choice;
    std::cin >> choice;
    
    if (choice == 'j' || choice == 'J') {
        // Spiel neu starten
        // Hier koennte man main() rekursiv aufrufen oder eine Schleife machen
    }
    
    return 0;
}

void printBoard(const std::array<char, BOARD_SIZE>& board) {
    std::cout << "\nTIC TAC TOE\n";
    std::cout << "===========\n";
    for (int i = 0; i < 9; i += 3) {
        std::cout << board[i] << " | " << board[i+1] << " | " << board[i+2] << "\n";
        if (i < 6) std::cout << "--+---+--\n";
    }
    std::cout << "\n";
}

bool makeMove(std::array<char, BOARD_SIZE>& board, int position, char player) {
    // Prüfen ob Feld noch eine Zahl ist (also frei)
    if (board[position] >= '1' && board[position] <= '9') {
        board[position] = player;
        return true;
    }
    return false;
}

bool checkWin(const std::array<char, BOARD_SIZE>& board, char player) {
    // Alle Gewinnkombinationen
    const int winPatterns[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8}, // Horizontal
        {0,3,6}, {1,4,7}, {2,5,8}, // Vertikal
        {0,4,8}, {2,4,6}           // Diagonal
    };
    
    for (const auto& pattern : winPatterns) {
        if (board[pattern[0]] == player &&
            board[pattern[1]] == player &&
            board[pattern[2]] == player) {
            return true;
        }
    }
    return false;
}

bool checkDraw(const std::array<char, BOARD_SIZE>& board) {
    // Prüfen ob alle Felder belegt sind
    for (char cell : board) {
        if (cell >= '1' && cell <= '9') {
            return false; // Es gibt noch freie Felder
        }
    }
    return true;
}
