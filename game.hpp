#include "entity.hpp"

//std
#include <memory>
#include <iostream>
#include <stdio.h>

class Game {
public:
	void run();
private:
	int stage;
	int turn;
	int deadMob;
	bool isEnemyDead;
	bool leveledUp;
	bool gameShouldStop;

	std::unique_ptr<Entity> player;
	std::unique_ptr<Entity> enemy;

	void initGame();
	void mainLoop();
	void TerminateGame();

	void clearConsole();

	std::unique_ptr<Entity> chooseHero(int stage);

	std::unique_ptr<Entity> makeTroll(int stage);
	std::unique_ptr<Entity> makeGoblin(int stage);
	std::unique_ptr<Entity> makeKnight(int stage);
	std::unique_ptr<Entity> makeWizard(int stage);

	void levelUp();

	void playerChooseAction();
	void enemyChooseAction();
};