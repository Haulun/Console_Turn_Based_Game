#include "knight.hpp"

namespace JeuConsole {
	Knight::Knight(std::string name) : Hero(name, KNIGHT) {}

	void Knight::absorbDmg() {
		m_shield = m_shieldMax;
	}
}