#include <sstream>
#include <iostream>
#include <climits>

int main(){
	/*
	std::istringstream s1("Hello, world.");
    char c1 = s1.get(); // reads 'H'
	char c2 = s1.get();
	
	std::cout << c1 << c2 << std::endl;
	*/

	uint8_t mask = 1 << (CHAR_BIT - 1);
	std::cout << mask << "\n";
	return 0;
}