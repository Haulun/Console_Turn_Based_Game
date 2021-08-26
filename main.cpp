#include "entity.hpp"
#include "knight.hpp"
#include "mage.hpp"
#include "troll.hpp"
#include "goblin.hpp"


#include <cstdlib>
#include <ctime>
#include <random>

#include <iostream>

using namespace JeuConsole;
using namespace std;

int main() {



	cout << "Choisissez une classe : \nM pour Mage \nK pour Knight" << endl;			
	char choice;

	Entity *player(0);
	Entity *enemy(0);


	while(choice != 'm' && choice != 'k'){
		cin >> choice;
		if(choice != 'm' && choice != 'k'){
			cout << "caractère non valide" << endl;
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
			int random = rand() % 2;

			if(random == 1){
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
		
		cout << "Attaquer! : appuyer sur a, Se défendre : appuyer sur s" << endl << endl;
		cin >> playerInput;

		if(playerInput == 'a'){	
			player->giveDmg(*enemy);
			cout << "vous attaquez votre ennemi ! "<< endl;
			cout << "il lui reste " << enemy->getLife() << " points de vie !" << endl << endl; 

		}
		else if(playerInput == 's'){
			cout << "vous vous défendez un peu pas trop" << endl << endl;
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

	cout << "game over quel dommage :(" << endl;



	// todo : penser à delete *player / *enemy
	delete enemy;
	delete player;


}