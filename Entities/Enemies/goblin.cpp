#include "goblin.hpp"

namespace JeuConsole {
	Goblin::Goblin(std::string name, int stage) : Enemy(name, GOBLIN, stage) {
		m_giveXp = 10;
	}

	void Goblin::absorbDmg() {
		m_shield = m_shieldMax;
	}
}