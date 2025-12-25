#include <iostream>
#include <array>

using std::cout, std::cin, std::string, std::endl;

const char PLAYER_X = 'X';
const char PLAYER_O = 'O';

void printboard(std::array<char, 9> &board) {
	cout << "\nTIC TAC TOE\n";
	cout << "===============\n";
	for (int i = 0; i < 9; i += 3) {
		cout << board[i] << " | " << board[i+1] << " | " << board[i+2] << "\n";
		if (i < 6) {
			cout << "--+---+--\n";
		}
	}
}

void move(char player) {
		
}

int main() {
	std::array<char, 9> board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	printboard(board);
	return 0;
}
