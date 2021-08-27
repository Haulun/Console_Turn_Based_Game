#include "mage.hpp"

namespace JeuConsole {
	Mage::Mage(std::string name) : Entity(name, MAGE) {}

	void Mage::absorbDmg() {
		m_shield = m_shieldMax;
	}
}