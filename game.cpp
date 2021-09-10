#include "game.hpp"

//MAIN FUNCTIONS

void Game::run()
{
	initGame();
	mainLoop();
	TerminateGame();
}

//Game Initialization
void Game::initGame()
{
	player = chooseHero();
}

//Game Loop
void Game::mainLoop()
{
	while (!gameShouldStop)
	{
		//Replay or not when the player dies :
		if (player->isDead())
		{
			gameShouldStop = true;
		}
		else
		{
			if (enemy->isDead())
			{
				if (enemy != nullptr)
				{
					handleEnemyDeath();
					createNewEnemy();
				}
				else
				{
					createNewEnemy();
				}
			}

			std::cout << "==========> TOUR " << turn << " <==========" << std::endl
					  << std::endl;
			turn += 1;

			playerRunAction();

			enemyRunAction();

			// Display lives :
			std::cout << " ENNEMI : " << enemy->getLife() << " points de vie !" << std::endl;
			std::cout << " VOUS : " << player->getLife() << " points de vie !" << std::endl
					  << std::endl;

			std::cout << "INFO : Vous avez actuellement " << player->getMana() << " points de mana" << std::endl
					  << std::endl;
		}
	}
}

//Game ends
void Game::TerminateGame()
{
	std::cout << "==========> Vous etes mort <==========" << std::endl;
	std::cout << "============> Fin du jeu <============" << std::endl
			  << std::endl;
	std::cout << "Etage atteint : " << stats["Score_Stage"] << std::endl;
	std::cout << "Niveau atteint : " << player->getLevel() << std::endl;
	std::cout << "Nombre de mobs tues : " << stats["Score_KilledMob"] << std::endl;

	//REMPLIR UN FICHIER DE DONNEES

	FileManager fileManager;
	fileManager.setScore(stats);
}

//OTHER FUNCTIONS :

std::unique_ptr<Entity> Game::chooseHero()
{
	std::cout << "Choisissez une classe : \n";
	std::cout << " - \"w\" pour Mage \n";
	std::cout << " - \"k\" pour Knight" << std::endl
			  << std::endl;

	std::string choice;

	do
	{
		std::cout << "Votre choix : ";
		std::cin >> choice;

		if (choice != "w" && choice != "k")
		{
			std::cout << std::endl
					  << "Caractere non valide" << std::endl
					  << std::endl;
		}
	} while (choice != "w" && choice != "k");

	if (choice == "w")
	{
		std::cout << std::endl
				  << "Vous avez choisi Jean(ne) le mage !" << std::endl
				  << std::endl;
		return entityMaker.makeWizard();
	}
	else
	{
		std::cout << std::endl
				  << "Vous avez choisi Arthure(ette) le chevalier !" << std::endl
				  << std::endl;
		return entityMaker.makeKnight();
	}
}

void Game::createNewEnemy()
{
	int category = rand() % 100;
	if (category < 35)
	{
		enemy = entityMaker.makeTroll(stats["Score_Stage"]);
		std::cout << "/!\\ Attention, un Troll apparait /!\\\n"
				  << std::endl;
		;
	}
	else if (category >= 35)
	{
		enemy = entityMaker.makeGoblin(stats["Score_Stage"]);
		std::cout << "/!\\ Attention, un Gobelin apparait /!\\\n"
				  << std::endl;
	}
	else
	{
		throw std::runtime_error("Impossible de creer l'ennemi");
	}
}

void Game::handleEnemyDeath()
{
	bool leveledUp = false;
	leveledUp = player->takeXp(enemy);

	std::cout << std::endl
			  << "INFO : Votre ennemi est mort dans d'atroces souffrances !" << std::endl;
	stats["Score_KilledMob"] += 1;
	std::cout << "INFO : Vous avez actuellement " << player->getXp() << " points d'experience" << std::endl
			  << std::endl;

	if (leveledUp == true)
	{
		eventLevelUp();

		if (canStageUp())
		{
			stats["Score_Stage"] += 1;
			std::cout << "INFO : Bravo ! Vous passez a l'etage suivant" << std::endl
					  << std::endl;
		}
	}
}

//UPGRADES :
void Game::eventLevelUp()
{
	std::string playerInput;

	std::cout << "INFO : Vous etes maintenant level " << player->getLevel() << " ! Bravo *clap* *clap* !" << std::endl
			  << std::endl;
	std::cout << "Choississez ce que vous voulez augmenter :" << std::endl;
	std::cout << " - \"life\" pour augmenter la vie de 10." << std::endl;
	std::cout << " - \"shield\" pour augmenter le bouclier de 5%." << std::endl;
	std::cout << " - \"attack\" pour augmenter l'attaque de 2." << std::endl
			  << std::endl;
	while (playerInput != "life" && playerInput != "shield" && playerInput != "attack")
	{
		std::cout << "Votre choix : ";
		std::cin >> playerInput;
		if (playerInput != "life" && playerInput != "shield" && playerInput != "attack")
		{
			std::cout << "Mot non valide" << std::endl;
		}
	}
	player->levelUp(playerInput);
	stats["Score_Level"]++;
}

bool Game::canStageUp()
{
	return player->getLevel() % 5 == 0;
}

//PLAYER ACTION :
void Game::playerRunAction()
{
	std::string choice = playerChooseAction();
	bool actionSuccess = playerExecuteAction(choice);
	playerDisplayAction(choice, actionSuccess);
}

std::string Game::playerChooseAction()
{
	std::string playerInput;

	std::cout << "Choisissez une action :" << std::endl;
	std::cout << "	- \"a\" pour attaquer.\n";
	std::cout << "	- \"s\" pour vous defendre.\n";
	std::cout << "	- \"h\" pour vous soigner.\n";
	std::cout << "	- \"q\" pour quitter le jeu" << std::endl
			  << std::endl;

	std::cout << "Votre choix : ";
	std::cin >> playerInput;
	std::cout << std::endl;

	return playerInput;
}

bool Game::playerExecuteAction(std::string choice)
{
	bool actionSuccess = true;
	if (choice == "a")
	{
		player->giveDamage(*enemy);
		player->incMana(5);
	}
	else if (choice == "s")
	{
		player->absorbDamage();
		enemy->resetShield();
		player->incMana(5);
	}
	else if (choice == "h")
	{
		if (player->healable())
		{
			player->heal();
		}
		else
		{
			actionSuccess = false;
		}
		enemy->resetShield();
	}
	else if (choice == "q")
	{
		gameShouldStop = true;
	}
	else
	{
		player->incMana(5);
		enemy->resetShield();
		actionSuccess = false;
	}
	return actionSuccess;
}

void Game::playerDisplayAction(std::string choice, bool actionSuccess)
{

	interface.clearConsole();

	if (choice == "a")
	{
		std::cout << "[ VOUS => ENNEMI ] Vous attaquez votre ennemi ! " << std::endl;
	}
	else if (choice == "s")
	{
		std::cout << "[ VOUS => VOUS ] Vous vous defendez jusqu'a la fin du tour. ";
		std::cout << "reduction de " << player->getShield() * 100 << "% des degats totaux !" << std::endl;
	}
	else if (choice == "h")
	{
		if (actionSuccess)
		{
			std::cout << "[ VOUS => VOUS ] Vous vous soignez avec 80 points de mana. ";
			std::cout << "Vous avez maintenant " << player->getLife() << " points de vie" << std::endl;
		}
		else
		{
			std::cout << "[ VOUS => VOUS ] Vous n'arrivez pas a vous soigner : vous n'avez pas assez de mana ou il vous reste plus de la moitie de votre vie." << std::endl;
		}
	}
	else if (choice == "q")
	{
	}
	else
	{
		std::cout << "INFO : Vous ratez votre coup..." << std::endl
				  << std::endl;
	}
}

//ENEMY ACTION :
void Game::enemyRunAction()
{
	std::string choice = enemyChooseAction();
	enemyExecuteAction(choice);
	enemyDisplayAction(choice);
}

std::string Game::enemyChooseAction()
{
	int random = rand() % 100;
	// shield
	if (random < 20 && enemy->getShield() == 1)
	{
		return "s"; //shield
	}
	//heal
	else if (random >= 20 && random < 45 && enemy->healable())
	{
		return "h"; //heal
	}
	// atk
	else
	{
		return "a"; //atk
	}
}

void Game::enemyExecuteAction(std::string choice)
{
	if (choice == "a")
	{ // attack
		enemy->giveDamage(*player);
		enemy->incMana(3);
	}
	else if (choice == "s")
	{ // shield
		enemy->absorbDamage();
		enemy->incMana(3);
		player->resetShield();
	}
	else if (choice == "h")
	{ // heal
		enemy->heal();
		player->resetShield();
	}
	else
	{
		throw std::runtime_error("Impossible d'executer l'action de l'ennemi");
	}
}

void Game::enemyDisplayAction(std::string choice)
{

	if (choice == "a")
	{ // attack
		std::cout << "[ VOUS <= ENNEMI ] L'ennemi fonce sur vous, vous perdez des points de vie !" << std::endl
				  << std::endl;
	}
	else if (choice == "s")
	{ // shield
		std::cout << "[ ENNEMI <= ENNEMI ] L'ennemi se prepare a absorber la prochaine attaque !" << std::endl
				  << std::endl;
	}
	else if (choice == "h")
	{ // heal
		std::cout << "[ ENNEMI <= ENNEMI ] L'ennemi se soigne !" << std::endl
				  << std::endl;
	}
	else
	{
		throw std::runtime_error("Impossible d'afficher l'action");
	}
}
