#include "entity.hpp"
#include "entitymaker.hpp"
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

	//Variables :
	int stage = 0;
	int turn = 1;
	int deadMob = 0;
	bool gameShouldStop = false;

	std::unique_ptr<Entity> player;
	std::unique_ptr<Entity> enemy;

	EntityMaker entityMaker;
	Interface interface;

	//Main functions
	void initGame();
	void mainLoop();
	void TerminateGame();

	//j'aime les p�tes
	std::unique_ptr<Entity> chooseHero();
	void createNewEnemy();
	void handleEnemyDeath();

	//Upgrades :
	void eventLevelUp();
	bool canStageUp();

	//Player actions :
	void playerRunAction();
	std::string playerChooseAction();
	bool playerExecuteAction(std::string choice);
	void playerDisplayAction(std::string choice, bool actionSuccess);

	//Enemy actions :
	void enemyRunAction();
	std::string enemyChooseAction();
	void enemyExecuteAction(std::string choice);
	void enemyDisplayAction(std::string choice);
};