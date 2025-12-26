#include <iostream>
#include <array>

using std::cout, std::cin, std::string, std::endl;

const char PLAYER_X = 'X';
const char PLAYER_O = 'O';
const int BOARD_SIZE = 9;

void printboard(std::array<char, BOARD_SIZE> &board) {
	cout << "\nTIC TAC TOE\n";
	cout << "===============\n";
	for (int i = 0; i < 9; i += 3) {
		cout << board[i] << " | " << board[i+1] << " | " << board[i+2] << "\n";
		if (i < 6) {
			cout << "--+---+--\n";
		}
	}
}

void move(std::array<char, BOARD_SIZE> &board, int position, char player) {
	board[position - 1] = player;
}

bool checkfilled(std::array<char, BOARD_SIZE> &board, int position) {
	if (board[position - 1] == 'O' || board[position - 1] == 'X'){
		return true;
	}
	return false;
}

bool checkwin(std::array<char, BOARD_SIZE> &board, char player) {
	const int winPattern[8][3] = {
		{0, 1, 2}, {3, 4, 5}, {6, 7, 8},
		{0, 3, 6}, {1, 4, 7}, {2, 5, 8},
		{0, 4, 8}, {2, 4, 6}
	};
	for (const auto &pattern : winPattern) {
		if (board[pattern[0]] == player &&
			board[pattern[1]] == player &&
			board[pattern[2]] == player) {
			return true;
		}
	}
	return false;
}

bool checkdraw(std::array<char, BOARD_SIZE> &board) {
	for (char x : board) {
		if (x >= '1' && x <= '9') {
			return false;
		}
	}
	return true;
}

int main() {
	std::array<char, BOARD_SIZE> board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	int position;
	while (true) {
		printboard(board);
		cout << "PLAYER_X to move pick a number: \n";
		bool moving = true;
		while (moving) {
			cin >> position;
			if (position >= 1 && position <= 9) {
				if (checkfilled(board, position)) {
					cout << "Pick another number this number is already picked\n";
				} else {
					move(board, position, PLAYER_X);
					moving = false;
				}
			} else {
				cout << "Please pick a number between 1 and 9 ONLY\n";
			}
		}
		printboard(board);
		if (checkwin(board, PLAYER_X)) {
			cout << "Congrats player X won\n";
			break;
		} else if (checkdraw(board)) {
			cout << "It's a draw";
			break;
		}
		cout << "PLAYER_O to move pick a number: \n";
		bool moving2 = true;
		while (moving2) {
			cin >> position;
			if (position >= 1 && position <= 9) {
				if (checkfilled(board, position)) {
					cout << "Pick another number this number is already picked\n";
				} else {
					move(board, position, PLAYER_O);
					moving2 = false;
				}
			} else {
				cout << "Please pick a number between 1 and 9 ONLY\n";
			}
		}
		if (checkwin(board, PLAYER_X)) {
			cout << "Congrats player X won\n";
			break;
		} else if (checkdraw(board)) {
			cout << "It's a draw";
			break;
		}
	}



	return 0;
}
