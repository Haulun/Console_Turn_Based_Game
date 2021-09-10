#ifndef DEF_GAME
#define DEF_GAME

#include "entity.hpp"
#include "entitymaker.hpp"
#include "interface.hpp"
#include "filemanager.hpp"

//std
#include <memory>
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <fstream>
#include <vector>

class Game {
public:
	void run();
	~Game() = default;
private:
	std::map<std::string, int> stats = { {"Score_Stage", 0}, {"Score_KilledMob", 0}, {"Score_Level", 0} };

	//Variables :
	int turn = 1;
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

#endif