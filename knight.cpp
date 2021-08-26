#include "knight.hpp"

namespace JeuConsole {
	Knight::Knight(std::string name) : Entity(name, KNIGHT) {}

	void Knight::absorbDmg() {
		m_shield = 0.50;
	}
}