#include "game.hpp"

//std
#include <stdexcept>

int main() {
	
	try {
		while (true) {

			Game game;
			game.run();

			std::string choice;
			std::cout << "Voulez-vous faire une partie: \n";
			std::cout << "	- \"o\" pour oui \n";
			std::cout << "	- \"n\" pour non \n\n";

			std::cout << "Votre choix : ";

			do {
				std::cin >> choice;

				if (choice != "o" && choice != "n") {
					std::cout << "Caractere non valide ! Veuillez reessayer\n\n";
				}
			} while (choice != "o" && choice != "n");
			if (choice == "n") {
				std::cout << std::endl << "INFO : Fermeture du jeu\n";
				break;
			}
		}
	}
	catch (std::runtime_error const& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}

