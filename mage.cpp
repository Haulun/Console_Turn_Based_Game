#include "mage.hpp"

namespace JeuConsole {
	Mage::Mage(std::string name) : Hero(name, MAGE) {}

	void Mage::absorbDmg() {
		m_shield = m_shieldMax;
	}
}