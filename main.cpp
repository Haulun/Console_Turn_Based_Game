#include "Entities/entity.hpp"

#include <cstdlib>
#include <iostream>

void makeEntity(Type type, Entity* const entity) {
	*entity = Entity(type);
}


int main() {

	Entity entity;
	makeEntity(Type::GOBLIN, &entity);

	std::cout << entity.getXp() << std::endl;

	bool gameShouldStop = false;

	while (gameShouldStop) {

	}

}
























//	cout << "Choisissez une classe : \n";
//	cout << " - \"m\" pour Mage \n";
//	cout << " - \"k\" pour Knight" << endl << endl;
//
//	string choice;
//
//	Entity *player(0);
//	Entity *enemy(0);
//
//
//	while(choice != "m" && choice != "k"){
//
//		cout << "Votre choix : ";
//		cin >> choice;
//
//		if(choice != "m" && choice != "k"){
//			cout << endl << "Caractere non valide" << endl << endl;
//		}
//	}
//
//	if(choice == "m"){
//		cout << endl << "Vous avez choisi Merlin le mage !" << endl << endl;
//		player = new Mage("Merlin");
//
//	}
//	else{
//		cout << endl << "Vous avez choisi Jeanne la chevaleresse !" << endl << endl;
//		player = new Knight("Jeanne");
//	}
//
//	bool isEnemyDead = true;
//	bool leveledUp = false;
//	int stage = 1;
//	int round = 1;
//	int deadMob = 0;
//
//	while(!player->isDead()){
//
//		cout << "==========> TOUR " << round << " <==========" << endl << endl;
//
//		//levelup + destroying + creation
//		if(isEnemyDead){
//			//If player leveled up
//			if(leveledUp) {
//				std::string playerInput;
//
//				cout << "INFO : Vous etes maintenant level " << player->getLevel() << " ! Bravo *clap* *clap* !" << endl << endl;
//				cout << "Choississez ce que vous voulez augmenter :" << endl;
//				cout << " - \"life\" pour augmenter la vie de 10." << endl;
//				cout << " - \"shield\" pour augmenter le bouclier de 5%." << endl;
//				cout << " - \"attack\" pour augmenter l'attaque de 2." << endl << endl;
//				while (playerInput != "life" && playerInput != "shield" && playerInput != "attack") {
//					cout << "Votre choix : ";
//					cin >> playerInput;
//					cout << endl;
//					if (playerInput == "life") {
//						player->incLife();
//						cout << "Vous avez maintenant " << player->getLife() << " points de vie !" << endl << endl;
//						
//					}
//					else if (playerInput == "shield") {
//						player->incShield();
//						cout << "Vous avez maintenant " << player->getShield() << " de defense !" << endl << endl;
//					}
//					else if(playerInput == "attack") {
//						player->incAtk();
//						cout << "Vous avez maintenant " << player->getAtk() << " d'attaque !" << endl << endl;
//					}
//					else
//					{
//						cout << "Quoi ?" << endl << endl;
//					}
//				}
//
//				leveledUp = false;
//			}
//
//			//We destroy the object that aim the pointer after the enemy dies (IMPORTANT)
//			delete enemy;
//			
//			//Create enemy : 2/5 -> Troll , 3/5 -> Gobelin
//			int random = rand() % 100;
//
//			if(random < 37){
//				enemy = new Troll("Troll", stage); 
//				cout << "/!\\ Attention un troll apparait /!\\" << endl << endl;
//			}
//			else{
//				enemy = new Goblin("Goblin", stage);
//				cout << "/!\\ Attention un goblin apparait /!\\" << endl << endl;
//			}
//			isEnemyDead = false;
//
//		}
//
//		// attacking / defending / healing
//		string playerInput;
//		
//		cout << "Choisissez une action :" << endl;
//		cout << " - \"a\" pour attaquer.\n";
//		cout << " - \"s\" pour vous defendre.\n";
//		cout << " - \"h\" pour vous soigner." << endl << endl;
//
//		cout << "Votre choix : ";
//		cin >> playerInput;
//		cout << endl;
//		if(playerInput == "a"){	
//			player->giveDmg(*enemy);
//			cout << "[ " <<player->getName() << " => " << enemy->getName() <<" ] Vous attaquez votre ennemi ! "<< endl;
//
//		}
//		else if(playerInput == "s"){
//			player->absorbDmg();
//			cout << "[ " << player->getName() << " => " << player->getName() << " ] Vous vous defendez. ";
//			cout << "Vous prenez " << player->getShield() * 100 << "% des degats totaux !" << endl << endl;
//			enemy->setShield(1);
//			
//			player->incMana(10);
//		}
//		else if(playerInput == "h"){
//			if (player->healable()) {
//				player->heal();
//				cout << "[ " << player->getName() << " => " << player->getName() << " ] Vous vous soignez.";
//				cout << "Vous avez maintenant " << player->getLife() << " points de vie et " << player->getMana() << " points de magie" << endl << endl;
//			}
//			else {
//				cout << "[ " << player->getName() << " => " << player->getName() << " ] Vous n'arrivez pas à vous soigner. " << player->getMana() << " points de magie restants\n" << endl;
//				
//			}
//			enemy->setShield(1);
//
//		}
//		else {
//			cout << "Vous ratez votre coup..." << endl << endl;
//			enemy->setShield(1);
//		}
//
//
//
//		if(enemy->isDead()) {
//			isEnemyDead = true;
//			leveledUp = player->takeXp(enemy->getGiveXp());
//			cout << endl << "INFO : Votre ennemi est mort dans d'atroces souffrances !" << endl;
//			player->incMana(20);
//			cout << "INFO : Vous avez recupere 10 points de mana" << endl << endl;
//			deadMob += 1;
//
//
//			if(leveledUp && player->getLevel()%5==0 && player->getLevel() != 0){
//				stage += 1;
//				cout << "INFO : Bravo ! Vous passez à l'etage suivant" << endl << endl;
//			}
//
//		} 
//
//
//		else {
//			int random = rand() % 100;
//			
//			// shield
//			if (random < 20 && enemy->getShield() == 1) {
//				enemy->absorbDmg();
//				cout << "[ " << enemy->getName() << " => " << enemy->getName() << " ] L'ennemi se prepare a absorber la prochaine attaque !" << endl << endl;
//			}
//			//heal
//			else if(random >= 20 && random < 45 && enemy->healable()) {
//				enemy->heal();
//				cout << "[ " << enemy->getName() << " => " << enemy->getName() << " ] L'ennemi se soigne !" << endl << endl;
//
//			}
//			// atk
//			else {
//				enemy->giveDmg(*player);
//				cout << "[ " << player->getName() << " <= " << enemy->getName() << " ] L'ennemi fonce sur vous, vous perdez des points de vie !" << endl << endl;
//	}
//		}
//
//
//		// Display life
//		cout  << enemy->getName() << " : " << enemy->getLife() << " points de vie !" <<  endl; 
//		cout  << player->getName() << " : " << player->getLife() << " points de vie !" << endl; 
//		cout << "INFO : Vous avez maintenant " << player->getMana() << " points de mana"<< endl << endl;
//
//
//		round += 1;
//
//	}
//
//		cout << "==========> Vous etes mort <==========" << endl << endl;
//		cout << "============> Fin du jeu <============" << endl << endl;
//
//		cout << "Etage atteint : " << stage << endl;
//		cout << "Niveau atteint : " << player->getLevel() << endl;
//		cout << "Nombre de mobs tues : " << deadMob << endl;
//
//
//	//Delete the player and the last enemy if the player dies
//	delete enemy;
//	delete player;



/*Enemy makeTroll() {
	return Enemy(
}*/