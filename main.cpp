#include "game.hpp"

//std
#include <stdexcept>

int main() {
	
	Game game;
	while(true){
		try {
			std::string choice;

			game.run();
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
				game.run();
			}
			else {
				break;
			}
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	return 0;
}

