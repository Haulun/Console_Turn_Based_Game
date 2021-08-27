#include "enemy.hpp"

namespace JeuConsole {
	Enemy::Enemy(std::string name, Category type, int stage) : Entity(name, type, stage) {}


	int Enemy::getGiveXp() const {
		return m_giveXp;
	}

	int Enemy::getXp() const {
		return 0;
	}

	int Enemy::getLevel() const {
		return 0;
	}

}

