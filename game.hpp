#include "entity.hpp"

//std
#include <memory>
#include <iostream>
#include <stdio.h>
#include <ctime>

class Game {
public:
	void run();
	~Game();
private:
	int stage;
	int turn;
	int deadMob;
	bool gameShouldStop;

	std::unique_ptr<Entity> player;
	std::unique_ptr<Entity> enemy;

	void initGame();
	void mainLoop();
	void TerminateGame();

	void clearConsole();

	std::unique_ptr<Entity> chooseHero();
	void createNewEnemy();
	void handleEnemyDeath();

	std::unique_ptr<Entity> makeTroll(int stage);
	std::unique_ptr<Entity> makeGoblin(int stage);
	std::unique_ptr<Entity> makeKnight();
	std::unique_ptr<Entity> makeWizard();

	void levelUp();

	void playerRunAction();
	void enemyChooseAction();
	void enemyExecuteAction(std::string choice);
};