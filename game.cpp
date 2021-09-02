#include "game.hpp"

void Game::run() {
	initGame();
	mainLoop();
	TerminateGame();
}

