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
		//Stopping if the player died :
		if (player->isDead())
		{
			std::cout << "==========> Vous etes mort <==========\n";
			gameShouldStop = true;
		}
		else //Keeping player if he hasn't yet :
		{
			if(enemy.get() != nullptr) {
				if (enemy->getType() == "boss" && enemy->isDead()) {
					std::cout << "===========> FELICITATIONS <===========\n";
					std::cout << "=====> TU AS BATTU LE BOSS FINAL <=====\n";
					gameShouldStop = true;
					continue;
				}
				else if (enemy->getType() != "boss" && enemy->isDead())
				{
					handleEnemyDeath();
					createNewEnemy();
				}
			}
			else {
				createNewEnemy();
			}
			
			std::cout << "==========> TOUR " << turn << " <==========\n\n";
			turn += 1;

			playerRunAction();

			enemyRunAction();

			// Display lives :
			std::cout << " ENNEMI : " << enemy->getLife() << " points de vie !\n";
			std::cout << " VOUS : " << player->getLife() << " points de vie !\n\n";

			std::cout << "INFO : Vous avez actuellement " << player->getMana() << " points de mana\n\n";
		}
	}
}

//Game ends
void Game::TerminateGame()
{
	std::cout << "==========> Fin de la partie <=========\n\n";
	std::cout << "Etage atteint : " << stats["Score_Stage"] << '\n';
	std::cout << "Niveau atteint : " << player->getLevel() << '\n';
	std::cout << "Nombre de mobs tues : " << stats["Score_KilledMob"] << "\n\n";

	//REMPLIR UN FICHIER DE DONNEES

	FileManager fileManager;
	std::cout << "INFO : (Re)ecriture de votre meilleur score dans score.txt\n";
	fileManager.setScore(stats);
}

//OTHER FUNCTIONS :

std::unique_ptr<Entity> Game::chooseHero()
{
	std::cout << "Choisissez une classe :\n";
	std::cout << " - \"w\" pour Mage \n";
	std::cout << " - \"k\" pour Knight\n\n";

	std::string choice;

	do
	{
		std::cout << "Votre choix : ";
		std::cin >> choice;

		if (choice != "w" && choice != "k")
		{
			std::cout << "\nCaractere non valide\n\n";
		}
	} while (choice != "w" && choice != "k");

	if (choice == "w")
	{
		std::cout << "\nVous avez choisi Jean(ne) le mage !\n\n";
		return entityMaker.makeWizard();
	}
	else
	{
		std::cout << "\nVous avez choisi Arthure(ette) le chevalier !\n\n";
		return entityMaker.makeKnight();
	}
}

void Game::createNewEnemy()
{
	int stage = stats["Score_Stage"];
	int category = rand() % 100;
	if (category < 35 && stage < 6)
	{
		enemy = entityMaker.makeTroll(stage);
		std::cout << R"(/!\\ Attention, un Troll apparait /!\)" << "\n\n";
		;
	}
	else if (category >= 35 && stage < 6)
	{
		enemy = entityMaker.makeGoblin(stage);
		std::cout << R"(/!\ Attention, un Gobelin apparait /!\)" << "\n\n";
	}
	else if (stage == 6) 
	{
		enemy = entityMaker.makeDragon();
		std::cout << R"(/!\ ATTENTION, UN IMMENSE DRAGON APPARAIT /!\)" << "\n\n";
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

	std::cout << "\nINFO : Votre ennemi est mort dans d'atroces souffrances !\n";
	stats["Score_KilledMob"] += 1;
	std::cout << "INFO : Vous avez actuellement " << player->getXp() << " points d'experience\n\n";

	if (leveledUp == true)
	{
		eventLevelUp();

		if (canStageUp())
		{
			if (stats["Score_Stage"] == 6) {
				
			}
			else {
				stats["Score_Stage"] += 1;
				std::cout << "INFO : Bravo ! Vous passez a l'etage suivant\n\n";
			}
 
		}
	}
}

//UPGRADES :
void Game::eventLevelUp()
{
	std::string playerInput;

	std::cout << "INFO : Vous etes maintenant level " << player->getLevel() << " ! Bravo *clap* *clap* !\n\n";
	std::cout << "Choississez ce que vous voulez augmenter :\n";
	std::cout << " - \"life\" pour augmenter la vie de 10.\n";
	std::cout << " - \"shield\" pour augmenter le bouclier de 5%.\n";
	std::cout << " - \"attack\" pour augmenter l'attaque de 2.\n\n";
	while (playerInput != "life" && playerInput != "shield" && playerInput != "attack")
	{
		std::cout << "Votre choix : ";
		std::cin >> playerInput;
		if (playerInput != "life" && playerInput != "shield" && playerInput != "attack")
		{
			std::cout << "Mot non valide\n";
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

	std::cout << "Choisissez une action :\n";
	std::cout << "	- \"a\" pour attaquer.\n";
	std::cout << "	- \"s\" pour vous defendre.\n";
	std::cout << "	- \"h\" pour vous soigner.\n";
	std::cout << "	- \"q\" pour quitter le jeu\n\n";

	std::cout << "Votre choix : ";
	std::cin >> playerInput;
	std::cout << '\n';

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

void Game::playerDisplayAction(std::string choice, bool const& actionSuccess)
{

	interface.clearConsole();

	if (choice == "a")
	{
		std::cout << "[ VOUS => ENNEMI ] Vous attaquez votre ennemi !\n";
	}
	else if (choice == "s")
	{
		std::cout << "[ VOUS => VOUS ] Vous vous defendez jusqu'a la fin du tour. ";
		std::cout << "reduction de " << player->getShield() * 100 << "% des degats totaux !\n";
	}
	else if (choice == "h")
	{
		if (actionSuccess)
		{
			std::cout << "[ VOUS => VOUS ] Vous vous soignez avec 80 points de mana. ";
			std::cout << "Vous avez maintenant " << player->getLife() << " points de vie\n";
		}
		else
		{
			std::cout << "[ VOUS => VOUS ] Vous n'arrivez pas a vous soigner : vous n'avez pas assez de mana ou il vous reste plus de la moitie de votre vie.\n";
		}
	}
	else if (choice == "q")
	{
	}
	else
	{
		std::cout << "INFO : Vous ratez votre coup...\n\n";
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
		std::cout << "[ VOUS <= ENNEMI ] L'ennemi fonce sur vous, vous perdez des points de vie !\n\n";
	}
	else if (choice == "s")
	{ // shield
		std::cout << "[ ENNEMI <= ENNEMI ] L'ennemi se prepare a absorber la prochaine attaque !\n\n";
	}
	else if (choice == "h")
	{ // heal
		std::cout << "[ ENNEMI <= ENNEMI ] L'ennemi se soigne !\n\n";
	}
	else
	{
		throw std::runtime_error("Impossible d'afficher l'action");
	}
}
