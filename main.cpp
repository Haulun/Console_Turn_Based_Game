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

		if(isEnemyDead){
			int random = rand() % 2;
			if(random == 0){
				enemy = new Troll("Troll"); 
			}
			else{
				enemy = new Goblin("Goblin");
			}
			isEnemyDead = false;

		}

		//on attaque

		// si l'enmi est mort recréer un enmi

		// sinon l'enmi atk




	}



	// todo : penser à delete *player / *enemy

}