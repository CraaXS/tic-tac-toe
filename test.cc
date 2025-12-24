#include <iostream>
#include <map>

int main()
{	
	std::map<std::string, char> table = {{"one", '1'}};
	std::cout << table["one"];
	table["one"] = '7';
	std::cout << table["one"];
	return 0;
}
