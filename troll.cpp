#include "troll.hpp"

namespace JeuConsole {
	Troll::Troll(std::string name, int stage) : Enemy(name, TROLL, stage) {
		m_giveXp = 50;
	}
	
	void Troll::absorbDmg() {
		m_shield = m_shieldMax;
	}

}