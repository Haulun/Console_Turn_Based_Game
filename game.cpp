#include "game.hpp"

//MAIN FUNCTIONS

void Game::run() {
	initGame();
	mainLoop();
	TerminateGame();
}

//Game Initialization
void Game::initGame() {
	stage = 0;
	turn = 1;
	deadMob = 0;
	isEnemyDead = true;
	gameShouldStop = false;

	player = chooseHero();
}

//Game Loop
void Game::mainLoop() {
	while (!gameShouldStop) {

		std::cout << "==========> TOUR " << turn << " <==========" << std::endl << std::endl;

		if (isEnemyDead) {
			createNewEnemy();
		}

		playerChooseAction();

		if (enemy->isDead()) {
			handleEnemyDeath();
		}
		else {
			enemyChooseAction();
		}

		turn += 1;

		//Replay or not when the player dies :

		if (player->isDead()) {
			std::string choice;

			std::cout << "==========> Vous etes mort <==========" << std::endl;
			std::cout << "============> Fin du jeu <============" << std::endl << std::endl;
			std::cout << "Etage atteint : " << stage << std::endl;
			std::cout << "Niveau atteint : " << player->getLevel() << std::endl;
			std::cout << "Nombre de mobs tues : " << deadMob << std::endl << std::endl;

			std::cout << "Voulez-vous recommencer : " << std::endl;
			std::cout << "	- \"o\" pour oui" << std::endl;
			std::cout << "	- \"n\" pour non" << std::endl;

			std::cout << "Votre choix : ";

			do {
				std::cin >> choice;

				if (choice != "o" && choice != "n") {
					std::cout << "Caractere non valide ! Veuillez reessayer\n" << std::endl;
				}
			} while (choice != "o" && choice != "n");

			if (choice == "o") {
				initGame();
			}
			else {
				TerminateGame();
			}
		}

		if (!gameShouldStop) {
			// Display lives :
			std::cout << enemy->getName() << " : " << enemy->getLife() << " points de vie !" << std::endl;
			std::cout << player->getName() << " : " << player->getLife() << " points de vie !" << std::endl << std::endl;

			std::cout << "INFO : Vous avez actuellement " << player->getMana() << " points de mana" << std::endl << std::endl;
		}
		else {
			std::cout << std::endl << "INFO : Fermeture du jeu" << std::endl;
		}
		
	}
}

//Game Closing
void Game::TerminateGame() {
	gameShouldStop = true;
}

//OTHER FUNCTIONS

void Game::clearConsole() {
	std::cout << "\x1B[2J\x1B[H";
}

std::unique_ptr<Entity> Game::chooseHero() {
	std::cout << "Choisissez une classe : \n";
	std::cout << " - \"w\" pour Mage \n";
	std::cout << " - \"k\" pour Knight" << std::endl << std::endl;

	std::string choice;

	do {
		std::cout << "Votre choix : ";
		std::cin >> choice;

		if (choice != "w" && choice != "k") {
			std::cout << std::endl << "Caractere non valide" << std::endl << std::endl;
		}
	} while (choice != "w" && choice != "k");

	if (choice == "w") {
		std::cout << std::endl << "Vous avez choisi Jean(ne) le mage !" << std::endl << std::endl;
		return makeWizard();

	}
	else {
		std::cout << std::endl << "Vous avez choisi Arthure(ette) le chevalier !" << std::endl << std::endl;
		return makeKnight();
	}
}

void Game::createNewEnemy() {
	int category = rand() % 100;
	if (category < 37) {
		enemy = makeTroll(stage);
		std::cout << "/!\\ Attention, un Troll apparait /!\\\n" << std::endl;;
	}
	else if (category >= 37) {
		enemy = makeGoblin(stage);
		std::cout << "/!\\ Attention, un Gobelin apparait /!\\\n" << std::endl;
	}
	else
	{
		std::cout << "Erreur a la creation de l'ennemi" << std::endl;
	}
	isEnemyDead = false;
}

void Game::handleEnemyDeath() {
	bool leveledUp = false;
	isEnemyDead = true;
	leveledUp = player->takeXp(enemy->getXp());
	std::cout << std::endl << "INFO : Votre ennemi est mort dans d'atroces souffrances !" << std::endl;
	deadMob += 1;

	if (leveledUp == true) {
		levelUp();
	}

	if (leveledUp && player->getLevel() % 5 == 0 && player->getLevel() != 0) {
		stage += 1;
		std::cout << "INFO : Bravo ! Vous passez à l'etage suivant" << std::endl << std::endl;

	}
}

std::unique_ptr<Entity> Game::makeTroll(int stage) {
	std::string name = "Hugue(ette)";
	int atk = 8 + stage * 2;
	int manaMax = 80;
	int lifeMax = 150 + stage * 15;
	double shieldMax = 0.9 - stage * 0.05;
	int xp = 30;

	return std::make_unique<Entity>(name, atk, manaMax, lifeMax, shieldMax, xp);
}

std::unique_ptr<Entity> Game::makeGoblin(int stage) {
	std::string name = "Michel(le)";
	int atk = 3 + stage * 1;
	int manaMax = 80;
	int lifeMax = 50 + stage * 10;
	double shieldMax = 0.65 - stage * 0.05;
	int xp = 10;

	return std::make_unique<Entity>(name, atk, manaMax, lifeMax, shieldMax, xp);
}

std::unique_ptr<Entity> Game::makeKnight() {
	std::string name = "Arthur(ette)";
	int atk = 15;
	int manaMax = 80;
	int lifeMax = 100;
	double shieldMax = 0.6;
	int xp = 0;

	return std::make_unique<Entity>(name, atk, manaMax, lifeMax, shieldMax, xp);
}

std::unique_ptr<Entity> Game::makeWizard() {
	std::string name = "Jean(ne)";
	int atk = 12;
	int manaMax = 110;
	int lifeMax = 80;
	double shieldMax = 0.6;
	int xp = 0;

	return std::make_unique<Entity>(name, atk, manaMax, lifeMax, shieldMax, xp);
}

void Game::levelUp() {
	std::string playerInput;

	std::cout << "INFO : Vous etes maintenant level " << player->getLevel() << " ! Bravo *clap* *clap* !" << std::endl << std::endl;
	std::cout << "Choississez ce que vous voulez augmenter :" << std::endl;
	std::cout << " - \"life\" pour augmenter la vie de 10." << std::endl;
	std::cout << " - \"shield\" pour augmenter le bouclier de 5%." << std::endl;
	std::cout << " - \"attack\" pour augmenter l'attaque de 2." << std::endl << std::endl;
	while (playerInput != "life" && playerInput != "shield" && playerInput != "attack") {
		std::cout << "Votre choix : ";
		std::cin >> playerInput;
		std::cout << std::endl;
		if (playerInput == "life") {
			player->incLifeMax(10);
			std::cout << "Vous avez maintenant " << player->getLife() << " points de vie !" << std::endl << std::endl;

		}
		else if (playerInput == "shield") {
			player->incShieldMax(0.05);
			std::cout << "Vous avez maintenant " << player->getShield() << " de defense !" << std::endl << std::endl;
		}
		else if (playerInput == "attack") {
			player->incAtk(2);
			std::cout << "Vous avez maintenant " << player->getAtk() << " d'attaque !" << std::endl << std::endl;
		}
		else
		{
			std::cout << "Caractere non valide" << std::endl << std::endl;
		}
	}
}

void Game::playerChooseAction() {
	std::string playerInput;

	std::cout << "Choisissez une action :" << std::endl;
	std::cout << "	- \"a\" pour attaquer.\n";
	std::cout << "	- \"s\" pour vous defendre.\n";
	std::cout << "	- \"h\" pour vous soigner.\n";
	std::cout << "	- \"q\" pour quitter le jeu" << std::endl << std::endl;

	std::cout << "Votre choix : ";
	std::cin >> playerInput;
	std::cout << std::endl;
	if (playerInput == "a") {
		clearConsole();

		player->giveDamage(*enemy);
		std::cout << "[ " << player->getName() << " => " << enemy->getName() << " ] Vous attaquez votre ennemi ! " << std::endl;
		player->incMana(5);
	}
	else if (playerInput == "s") {
		clearConsole();

		player->absorbDamage();
		std::cout << "[ " << player->getName() << " => " << player->getName() << " ] Vous vous defendez. ";
		std::cout << "Vous prenez " << player->getShield() * 100 << "% des degats totaux !" << std::endl;
		enemy->setShield(1);
		player->incMana(5);
	}
	else if (playerInput == "h") {
		clearConsole();


		if (player->heal()) {
			std::cout << "[ " << player->getName() << " => " << player->getName() << " ] Vous vous soignez.";
			std::cout << "Vous avez maintenant " << player->getLife() << " points de vie et " << player->getMana() << " points de magie" << std::endl;
		}
		else {

			std::cout << "[ " << player->getName() << " => " << player->getName() << " ] Vous n'arrivez pas à vous soigner. " << player->getMana() << " points de magie restants" << std::endl;

		}
		enemy->setShield(1);

	}
	else if (playerInput == "q") {
		clearConsole();

		gameShouldStop = true;

	}
	else {
		clearConsole();	
		std::cout << "Vous ratez votre coup..." << std::endl << std::endl;
		player->incMana(5);
		enemy->setShield(1);
	}
}

void Game::enemyChooseAction() {
	int random = rand() % 100;

	// shield
	if (random < 20 && enemy->getShield() == 1) {
		enemy->absorbDamage();
		std::cout << "[ " << enemy->getName() << " => " << enemy->getName() << " ] L'ennemi se prepare a absorber la prochaine attaque !" << std::endl << std::endl;
		enemy->incMana(3);
	}
	//heal
	else if (random >= 20 && random < 45 && enemy->getLife() <= enemy->getLifeMax() / 2 && enemy->heal()) {
		std::cout << "[ " << enemy->getName() << " => " << enemy->getName() << " ] L'ennemi se soigne !" << std::endl << std::endl;
	}
	// atk
	else {
		enemy->giveDamage(*player);
		std::cout << "[ " << player->getName() << " <= " << enemy->getName() << " ] L'ennemi fonce sur vous, vous perdez des points de vie !" << std::endl << std::endl;
		enemy->incMana(3);
	}
}