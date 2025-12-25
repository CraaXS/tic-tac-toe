#include <iostream>
#include <array>

using std::cout, std::cin, std::string, std::endl;

const char PLAYER_X = 'X';
const char PLAYER_O = 'O';
const int BOARD_SIZE = 9;

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

bool move(std::array<char, BOARD_SIZE> &board, int position, char player) {
	if (board[position] >= '1' && board[position] <= '9') {
		board[position - 1] = player;
		return true;
	} 
	return false;
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
	bool playing = true;
	int position, position2;
	while (playing) {
		bool play = true;
		bool play2 = true;
		printboard(board);
		while (play) {
			cout << "Player X to move pick a number: \n";
			bool move_ = true;
			while (move_){
				cin >> position;
				if (position >= 1 && position <= 9) {
					move_ = false;
				} else {
					cout << "Invalid number please pick a number between 1 and 9: \n";
				}
			}
			if (checkfilled(board, position) == false){
				move(board, position, PLAYER_X);
				play = false;
			} else {
				cout << "This position is already taken\n"; 
			}
		}
		printboard(board);
		while (play2) {
			cout << "Player O to move pick a number: \n";
			bool _move = true;
			while (_move){
				cin >> position2;
				if (position2 >= 1 && position2 <= 9) {
					_move = false;
				} else {
					cout << "Invalid number please pick a number between 1 and 9: \n";
				}
			}
			if (checkfilled(board, position2) == false){
				move(board, position2, PLAYER_O);
				play2 = false;
			} else {
				cout << "This position is already taken\n"; 
			}
		}
		if (checkwin(board, PLAYER_X) == true) {
			cout << "Player X won\n";
			playing = false;
		} else if (checkwin(board, PLAYER_O) == true) {
			cout << "Player O won\n";
			playing = false;
		}
		if (checkdraw(board)) {
			cout << "It's a draw";
			playing = false;
		}
	}
	return 0;
}
