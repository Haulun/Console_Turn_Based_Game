#include "hero.hpp"

namespace JeuConsole {
	Hero::Hero(std::string name, Category type) : Entity(name, type) {}

	int Hero::getXp() const {
		return m_xp;
	}

	int Hero::getLevel() const {
		return m_level;
	}

	bool Hero::takeXp(int xp){
		m_xp += xp;
		if (m_xp >= m_xpMax) {
			levelUp();
			return true;
		}
		return false;
	}

	void Hero::levelUp() {
		m_level += 1;
		m_xp = m_xp - m_xpMax;
	}

	void Hero::incLife() {
		m_lifeMax += 10;
		m_life = m_lifeMax;
	}

	void Hero::incShield() {
		m_shieldMax -= 0.05;
		if (m_shieldMax < 0) {
			m_shieldMax = 0;
		}
	}

	void Hero::incAtk() {
		m_atk += 2;
	}
}

