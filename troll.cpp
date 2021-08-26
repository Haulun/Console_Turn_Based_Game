#include "troll.hpp"

namespace JeuConsole {
	Troll::Troll(std::string name) : Entity(name, TROLL) {}
	
	void Troll::absorbDmg() {
		m_shield = 0.9;
	}

}