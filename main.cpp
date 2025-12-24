#include <iostream>
#include <map>

using std::cout, std::cin, std::string, std::endl;

int main() {
	std::map<string, char> table = {{"one", '1'}, {"two", '2'}, {"three", '3'}, {"four", '4'}, {"five", '5'}, {"six", '6'}, {"seven", '7'}, {"eight", '8'}, {"nine", '9'}};
	char one = table["one"];
	char two = table["two"];
	char three = table["three"];
	char four = table["four"];
	char five = table["five"];
	char six = table["six"];
	char seven = table["seven"];
	char eight = table["eight"];
	char nine = table["nine"];

	bool playing = true;

	while (playing) {
		char posx;
		char posy;
		cout << "TIC TAC TOE\n";
		cout << "===========\n";
		cout << one << '|' << two << '|' << three << '\n';
		cout << four << '|' << five << '|' << six << '\n';
		cout << seven << '|' << eight << '|' << nine << '\n';

		cout << "X => Pick a Position to mark: ";
		cin >> posx;
		cout << "O => Pick a Position to mark: ";
		cin >> posy;

		switch (posx) {
			case '1':
				one = 'X';
				break;
			case '2':
				two = 'X';
				break;
			case '3':
				three = 'X';
				break;
			case '4':
				four = 'X';
				break;
			case '5':
				five = 'X';
				break;
			case '6':
				six = 'X';
				break;
			case '7':
				seven = 'X';
				break;
			case '8':
				eight = 'X';
				break;
			case '9':
				nine = 'X';
				break;
		}
		switch (posy) {
			case '1':
				one = 'O';
				break;
			case '2':
				two = 'O';
				break;
			case '3':
				three = 'O';
				break;
			case '4':
				four = 'O';
				break;
			case '5':
				five = 'O';
				break;
			case '6':
				six = 'O';
				break;
			case '7':
				seven = 'O';
				break;
			case '8':
				eight = 'O';
				break;
			case '9':
				nine = 'O';
				break;
		}
	}
	return 0;
}
