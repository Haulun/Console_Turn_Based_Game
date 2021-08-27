#include "entity.hpp"
#include "knight.hpp"
#include "mage.hpp"
#include "troll.hpp"
#include "goblin.hpp"
#include "hero.hpp"
#include "enemy.hpp"

#include <cstdlib>
#include <iostream>
#include <istream>


using namespace JeuConsole;
using namespace std;

int main() {


	cout << "Choisissez une classe : \n";
	cout << " - \"m\" pour Mage \n";
	cout << " - \"k\" pour Knight" << endl << endl;

	string choice;

	Entity *player(0);
	Entity *enemy(0);


	while(choice != "m" && choice != "k"){

		cout << "Votre choix : ";
		cin >> choice;

		if(choice != "m" && choice != "k"){
			cout << endl << "Caractere non valide" << endl << endl;
		}
	}

	if(choice == "m"){
		cout << endl << "Vous avez choisi Merlin le mage !" << endl << endl;
		player = new Mage("Merlin");

	}
	else{
		cout << endl << "Vous avez choisi Jeanne la chevaleresse !" << endl << endl;
		player = new Knight("Jeanne");
	}

	bool isEnemyDead = true;
	bool leveledUp = false;
	int stage = 1;
	int round = 1;
	int deadMob = 0;

	while(!player->isDead()){

		cout << "==========> TOUR " << round << " <==========" << endl << endl;

		//levelup + destroying + creation
		if(isEnemyDead){
			//If player leveled up
			if(leveledUp) {
				std::string playerInput;

				cout << "Vous etes maintenant level " << player->getLevel() << " ! Bravo *clap* *clap* !" << endl << endl;
				cout << "Choississez ce que vous voulez augmenter :" << endl;
				cout << " - \"life\" pour augmenter la vie de 10." << endl;
				cout << " - \"shield\" pour augmenter le bouclier de 5%." << endl;
				cout << " - \"attack\" pour augmenter l'attaque de 2." << endl << endl;
				while (playerInput != "life" && playerInput != "shield" && playerInput != "attack") {
					cout << "Votre choix : ";
					cin >> playerInput;
					cout << endl;
					if (playerInput == "life") {
						player->incLife();
						cout << "Vous avez maintenant " << player->getLife() << " points de vie !" << endl << endl;
						
					}
					else if (playerInput == "shield") {
						player->incShield();
						cout << "Vous avez maintenant " << player->getShield() << " de defense !" << endl << endl;
					}
					else if(playerInput == "attack") {
						player->incAtk();
						cout << "Vous avez maintenant " << player->getAtk() << " d'attaque !" << endl << endl;
					}
					else
					{
						cout << "Quoi ?" << endl << endl;
					}
				}

				leveledUp = false;
			}

			//We destroy the object that aim the pointer after the enemy dies (IMPORTANT)
			delete enemy;
			
			//Create enemy : 2/5 -> Troll , 3/5 -> Gobelin
			int random = rand() % 100;

			if(random < 37){
				enemy = new Troll("Troll", stage); 
				cout << "/!\\ Attention un troll apparait /!\\" << endl << endl;
			}
			else{
				enemy = new Goblin("Goblin", stage);
				cout << "/!\\ Attention un goblin apparait /!\\" << endl << endl;
			}
			isEnemyDead = false;

		}

		// attacking / defending / healing
		string playerInput;
		
		cout << "Choisissez une action :" << endl;
		cout << " - \"a\" pour attaquer.\n";
		cout << " - \"s\" pour vous defendre.\n";
		cout << " - \"h\" pour vous soigner." << endl << endl;

		cout << "Votre choix : ";
		cin >> playerInput;
		cout << endl;
		if(playerInput == "a"){	
			player->giveDmg(*enemy);
			cout << "[ " <<player->getName() << " => " << enemy->getName() <<" ] Vous attaquez votre ennemi ! "<< endl;

		}
		else if(playerInput == "s"){
			player->absorbDmg();
			cout << "[ " << player->getName() << " => " << player->getName() << " ] Vous vous defendez. ";
			cout << "Vous prenez " << player->getShield() * 100 << "% des degats totaux !" << endl << endl;
		}
		else if(playerInput == "h"){
			player->heal();
			cout << "[ " << player->getName() << " => " << player->getName() << " ] Vous vous soignez.";
			cout << " Vous avez maintenant " << player->getLife() << " points de vie !" << endl << endl;

		}
		else {
			cout << "Vous ratez votre coup..." << endl << endl;
		}

		if(enemy->isDead()) {
			isEnemyDead = true;
			leveledUp = player->takeXp(enemy->getGiveXp());
			cout << "Votre ennemi est mort dans d'atroces souffrances !" << endl;
			cout << "Vous avez : " << player->getXp() << " d'xp" << endl << endl;

			deadMob += 1;


			if(leveledUp && player->getLevel()%5==0 && player->getLevel() != 0){
				stage += 1;
				cout << "Bravo ! Vous passez à l'etage suivant" << endl << endl;
			}

		} 
		else {
			int random = rand() % 3;
			if (random == 0 && enemy->getShield() == 1) {
				enemy->absorbDmg();
				cout << "[ " << enemy->getName() << " => " << enemy->getName() << " ] L'ennemi se prepare a absorber la prochaine attaque !" << endl << endl;
			}
			else {
				enemy->giveDmg(*player);
				cout << "[ " << player->getName() << " <= " << enemy->getName() << " ] L'ennemi fonce sur vous, vous perdez des points de vie !" << endl << endl;
			}
			
		}


		// display life
		cout  << enemy->getName() << " : " << enemy->getLife() << " points de vie !" <<  endl; 
		cout  << player->getName() << " : " << player->getLife() << " points de vie !" << endl << endl; 

		round += 1;
	}

		cout << "==========> Fin du jeu <==========" << endl << endl;

		cout << "Etage atteint : " << stage << endl;
		cout << "Niveau atteint : " << player->getLevel() << endl;
		cout << "Nombre de mobs tués : " << deadMob << endl;


	//Delete the player and the last enemy if the player dies
	delete enemy;
	delete player;
}