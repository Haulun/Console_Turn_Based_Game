#include "entity.hpp"
#include "knight.hpp"
#include "mage.hpp"
#include "troll.hpp"
#include "goblin.hpp"
#include "hero.hpp"
#include "enemy.hpp"

#include <cstdlib>
#include <iostream>

using namespace JeuConsole;
using namespace std;

int main() {


	cout << "Choisissez une classe : \nm pour Mage \nk pour Knight" << endl;			
	char choice = 'a';

	Entity *player(0);
	Entity *enemy(0);


	while(choice != 'm' && choice != 'k'){
		cin >> choice;
		if(choice != 'm' && choice != 'k'){
			cout << "caractere non valide" << endl;
		}
	}

	if(choice == 'm'){
		cout << "Vous avez choisi Merlin le mage !" << endl;
		player = new Mage("Merlin");

	}
	else{
		cout << "Vous avez choisi Arthur le chevalier !" << endl;
		player = new Knight("Arthur");
	}

	bool isEnemyDead = true;
	bool leveledUp = false;
	int stage = 0;


	while(!player->isDead()){

		//levelup + destroying + creation
		if(isEnemyDead){
			//If player leveled up
			if(leveledUp) {
				std::string playerInput;

				cout << "Vous etes maintenant level " << player->getLevel() << " ! Bravo *clap* *clap* !" << endl;
				cout << "choississez ce que vous voulez augmenter" << endl;
				cout << "\"life\" pour augmenter la vie" << endl;
				cout << "\"shield\" pour augmenter le bouclier" << endl;
				cout << "\"attack\" pour augmenter l'attaque" << endl;
				while (playerInput != "life" && playerInput != "shield" && playerInput != "attack") {
					cin >> playerInput;
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
						cout << "quoi ?" << endl << endl;
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
				cout << "attention un troll apparait !" << endl << endl;
			}
			else{
				enemy = new Goblin("Goblin", stage);
				cout << "attention un goblin apparait !" << endl << endl;
			}
			isEnemyDead = false;

		}

		// attacking / defending / healing
		char playerInput;
		
		cout << "Pour attaquer : appuyer sur a.\n";
		cout << "Pour vous defendre : appuyer sur s.\n";
		cout << "Pour vous soigner : appuyer sur h." << endl << endl;
		cin >> playerInput;

		if(playerInput == 'a'){	
			player->giveDmg(*enemy);
			cout << "vous attaquez votre ennemi ! "<< endl;
			cout << "il lui reste " << enemy->getLife() << " points de vie !" << endl << endl; 

		}
		else if(playerInput == 's'){
			player->absorbDmg();
			cout << "vous vous defendez. Vous prenez " << player->getShield() * 100 << "% des degats totaux" << endl << endl;
		}
		else if(playerInput == 'h'){
			player->heal();
			cout << "vous vous soignez" << endl;
			cout << "vous avez maintenant " << player->getLife() << " points de vie !" << endl << endl;

		}
		else {
			cout << "vous ratez votre coup" << endl << endl;
		}

		if(enemy->isDead()) {
			isEnemyDead = true;
			leveledUp = player->takeXp(enemy->getGiveXp());
			cout << "votre ennemi est mort dans d'atroces souffrances !" << endl;
			cout << "Vous avez : " << player->getXp() << " d'xp" << endl << endl;


			if(leveledUp && player->getLevel()%5==0 && player->getLevel() != 0){
				stage += 1;
				cout << "vous passez à l'étage suivant" << endl << endl;
			}

		} 
		else {
			int random = rand() % 3;
			if (random == 0 && enemy->getShield() == 1) {
				enemy->absorbDmg();
				cout << "L'ennemi se prepare a absorber la prochaine attaque" << endl << endl;
			}
			else {
				enemy->giveDmg(*player);
				cout << "l'ennemi fonce sur vous, vous perdez des points de vie !" << endl;
				cout << "points de vie restant : " << player->getLife() << endl << endl;
			}
			
		}
	}

	cout << "game over, quel dommage :(" << endl;

	//Delete the player and the last enemy if the player dies
	delete enemy;
	delete player;
}