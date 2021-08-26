#ifndef DEF_ENTITY
#define DEF_ENTITY

#include "entity.hpp"

namespace JeuConsole {
	Entity::Entity(std::string name) : m_name(name) {
		
	}
	Entity::Entity(int life, std::string name, int shield, int atk) : m_life(life), m_name(name), m_shield(shield), m_atk(atk) {}

	Entity::~Entity() {};

	void Entity::giveDmg(Entity& cible) {
		cible.takeDmg(m_atk);
	}

	void Entity::takeDmg(int atk) {
		m_life -= atk;
		if (m_life < 0) {
			m_life = 0;
		}
	}

	bool Entity::isDead() {
		return m_life == 0;
	}

	std::string Entity::getName() {
		return m_name;
	}

	int Entity::getLife() {
		return m_life;
	}
}
#endif