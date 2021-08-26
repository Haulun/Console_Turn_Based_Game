#include "entity.hpp"
#include "knight.hpp"
#include "mage.hpp"
#include <iostream>

using namespace JeuConsole;

int main() {

	Mage e1 = Mage("Robert");
	Knight e2 = Knight("Didier");

/*	std::cout << e1.getName() << std::endl;
	std::cout << e1.getType() << std::endl;
	std::cout << e1.getShield() << std::endl;
	std::cout << e1.getLife() << std::endl;
	std::cout << e1.getAtk() << "\n" << std::endl;
*/


	std::cout << e2.getName() << std::endl;
	std::cout << e2.getType() << std::endl;
	std::cout << e2.getShield() << std::endl;
	std::cout << e2.getLife() << std::endl;
	std::cout << e2.getAtk() << "\n" << std::endl;

}