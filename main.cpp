#include "game.hpp"

//std
#include <stdexcept>

int main() {
	
	Game game;

	try {
		game.run();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

