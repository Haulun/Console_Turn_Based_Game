#include "goblin.hpp"

namespace JeuConsole {
	Goblin::Goblin(std::string name) : Enemy(name, GOBLIN) {
		m_giveXp = 10;
	}

	void Goblin::absorbDmg() {
		m_shield = m_shieldMax;
	}
}