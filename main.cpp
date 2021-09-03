#include "game.hpp"

//std
#include <stdexcept>

int main() {
	
		try {
			while(true){

				Game game;
				game.run();

				std::string choice;
				std::cout << "Voulez-vous faire une partie: " << std::endl;
				std::cout << "	- \"o\" pour oui" << std::endl;
				std::cout << "	- \"n\" pour non" << std::endl << std::endl;;

				std::cout << "Votre choix : ";

				do {
					std::cin >> choice;

					if (choice != "o" && choice != "n") {
						std::cout << "Caractere non valide ! Veuillez reessayer\n" << std::endl;
					}
				} while (choice != "o" && choice != "n");
		
				if (choice == "n") {
					break;
				}

				game.~Game();
			
			}
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	return 0;
}

