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

	void levelUp();
	bool canStageUp();

	void playerRunAction();
	void enemyChooseAction();
	void enemyExecuteAction(std::string choice);
};