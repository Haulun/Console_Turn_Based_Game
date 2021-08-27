#include "entity.hpp"
#include "knight.hpp"
#include "mage.hpp"
#include "troll.hpp"
#include "goblin.hpp"


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

	while(!player->isDead()){

		
		// create enemy if enemy is dead
		if(isEnemyDead){
			int random = rand() % 3;

			if(random == 0){
				enemy = new Troll("Troll"); 
				cout << "attention un troll apparait !" << endl << endl;
			}
			else{
				enemy = new Goblin("Goblin");
				cout << "attention un goblin apparait !" << endl << endl;
			}
			isEnemyDead = false;

		}

		// attack
		char playerInput;
		
		cout << "Pour attaquer : appuyer sur a.\n Pour vous defendre : appuyer sur s.\n Pour vous soigner : appuyer sur h." << endl << endl;
		cin >> playerInput;

		if(playerInput == 'a'){	
			player->giveDmg(*enemy);
			cout << player->getLife() << endl;;
			cout << enemy->getLife() << endl;
			cout << "vous attaquez votre ennemi ! "<< endl;
			cout << "il lui reste " << enemy->getLife() << " points de vie !" << endl << endl; 

		}
		else if(playerInput == 's'){
			player->absorbDmg();
			cout << "vous vous defendez" << endl << endl;
		}
		else if(playerInput == 'h'){
			player->heal();
			cout << "vous vous soignez" << endl;
			cout << "vous avez maintenant " << player->getLife() << " points de vie !" << endl << endl;

		}
		else{
			cout << "vous ratez votre coup" << endl << endl;
		}

		if(enemy->isDead()){
			isEnemyDead = true;
			cout << "votre ennemi est mort dans d'atroces souffrances !" << endl << endl;

		} else {

			enemy->giveDmg(*player);
			cout << "l'ennemi fonce sur vous, vous perdez des points de vie !" << endl;
			cout << "points de vie restant : " << player->getLife() << endl << endl;;

		}
	}

	cout << "game over, quel dommage :(" << endl;

	delete enemy;
	delete player;
}