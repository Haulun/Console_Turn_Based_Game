#include "interface.hpp"

void Interface::clearConsole() const {
	std::cout << "\x1B[2J\x1B[H";
}
