#include "hero.hpp"

namespace JeuConsole {
	Hero::Hero(std::string name, Category type) : Entity(name, type) {}

	int Hero::getXp() const {
		return m_xp;
	}

	void Hero::takeXp(int xp){
		m_xp += xp; 
	}


}

