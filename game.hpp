#include "entity.hpp"

//std
#include <memory>
#include <iostream>
#include <stdio.h>

class Game {
public:
	void run();
private:
	int stage = 0;
	int turn = 0;
	int deadMob = 0;
	bool isEnemyDead = false;
	bool leveledUp = false;
	bool gameShouldStop = false;

	std::unique_ptr<Entity> player;
	std::unique_ptr<Entity> enemy;

	void initGame();
	void mainLoop();
	void TerminateGame();

	void clearConsole();

	std::unique_ptr<Entity> chooseHero();

	std::unique_ptr<Entity> makeTroll(int stage);
	std::unique_ptr<Entity> makeGoblin(int stage);
	std::unique_ptr<Entity> makeKnight();
	std::unique_ptr<Entity> makeWizard();

	void levelUp();

	void playerChooseAction();
	void enemyChooseAction();
};