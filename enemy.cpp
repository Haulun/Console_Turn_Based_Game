#include "enemy.hpp"

namespace JeuConsole {
	Enemy::Enemy(std::string name, Category type) : Entity(name, type) {}


	int Enemy::getGiveXp() const {
		return m_giveXp;
	}


}

