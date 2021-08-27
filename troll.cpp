#include "troll.hpp"

namespace JeuConsole {
	Troll::Troll(std::string name) : Enemy(name, TROLL) {
		m_giveXp = 50;
	}
	
	void Troll::absorbDmg() {
		m_shield = 0.9;
	}

}