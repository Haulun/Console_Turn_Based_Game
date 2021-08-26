#include "goblin.hpp"

namespace JeuConsole {
	Goblin::Goblin(std::string name) : Entity(name, GOBLIN) {}

	void Goblin::absorbDmg() {
		m_shield = 0.65;
	}
}