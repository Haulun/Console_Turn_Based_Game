#include "entity.hpp"

namespace JeuConsole {
	Entity::Entity(std::string name, Category type) : m_name(name), m_type(type) {
		switch(m_type) {
			case KNIGHT:
				m_life=100;
				m_atk=12;
				m_shield=5;
				break;
			case MAGE:
				m_life=90;
				m_atk=13;
				m_shield=1;
				break;
			case GOBLIN:
				m_life=50;
				m_atk=3;
				m_shield=0;
				break;
			case TROLL:
				m_life=150;
				m_atk=4;
				m_shield=0;
				break;
		}
	}

	Entity::Entity(int life, std::string name, int shield, int atk, Category type) : m_life(life), m_name(name), m_shield(shield), m_atk(atk), m_type(type) {}

	Entity::~Entity() {};

	void Entity::giveDmg(Entity& cible) const{
		cible.takeDmg(m_atk);
	}

	void Entity::takeDmg(int atk) {
		m_life -= atk;
		if (m_life < 0) {
			m_life = 0;
		}
	}

	bool Entity::isDead() const {
		return m_life == 0;
	}


	// get functions 

	std::string Entity::getName() const{
		return m_name;
	}

	int Entity::getLife()  const{
		return m_life;
	}

	int Entity::getAtk() const{
		return m_atk;
	}
	

	int Entity::getShield() const{
		return m_shield;
	}

	int Entity::getType() const{
		return m_type;
	}
	
		
}