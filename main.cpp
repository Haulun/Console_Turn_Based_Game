#include "entity.hpp"
#include "knight.hpp"
#include <iostream>

using namespace JeuConsole;

int main() {

	Knight e1 = Knight("Robert");
	Knight e2 = Knight("Didier");

	while(!e1.isDead() && !e2.isDead()){
		e1.giveDmg(e2);
		std::cout << e1.getName() << " attacks " << e2.getName() << std::endl;
		e2.giveDmg(e1);
		std::cout << e2.getName() << " attacks " << e1.getName() << std::endl << std::endl;

		std::cout << "life of " << e2.getName() << " is " << e2.getLife() << std::endl;
		std::cout << "life of " << e1.getName() << " is " << e1.getLife() << std::endl << std::endl;
	}

	std::cout << "End of fight :\n ";
	if(e1.isDead()){
		std::cout << e2.getName() << " won" << std::endl;
	} else {
		std::cout << e1.getName() << " won" << std::endl;
	}
}