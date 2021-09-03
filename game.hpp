#include "entity.hpp"
#include "interface.hpp"

//std
#include <memory>
#include <iostream>
#include <stdio.h>
#include <ctime>

class Game {
public:
	void run();
	~Game() = default;
private:
	int stage = 0;
	int turn = 1;
	int deadMob = 0;
	bool gameShouldStop = false;

	std::unique_ptr<Entity> player;
	std::unique_ptr<Entity> enemy;

	Interface interface;

	void initGame();
	void mainLoop();
	void TerminateGame();

	std::unique_ptr<Entity> chooseHero();
	void createNewEnemy();
	void handleEnemyDeath();

	std::unique_ptr<Entity> makeTroll(int stage);
	std::unique_ptr<Entity> makeGoblin(int stage);
	std::unique_ptr<Entity> makeKnight();
	std::unique_ptr<Entity> makeWizard();

	void eventLevelUp();
	bool canStageUp();

	void playerRunAction();
	std::string playerChooseAction();
	bool playerExecuteAction(std::string choice);
	void playerDisplayAction(std::string choice, bool actionSuccess);

	void enemyRunAction();
	std::string enemyChooseAction();
	void enemyExecuteAction(std::string choice);
	void enemyDisplayAction(std::string choice);
};