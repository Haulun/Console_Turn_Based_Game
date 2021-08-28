#include "entity.hpp"

namespace JeuConsole {
	Entity::Entity(std::string name, Category type) : m_name(name), m_type(type) {
		switch(m_type) {
			case KNIGHT:
				m_life=100;
				m_atk=12;
				m_shield=1;
				m_shieldMax = 0.5;
				m_mana = 90;
				break;
			case MAGE:
				m_life=90;
				m_atk=13;
				m_shield=1;
				m_shieldMax = 0.3;
				m_mana = 100;
				break;
			case GOBLIN:
				m_life=50;
				m_atk=3;
				m_shield=1;
				m_shieldMax = 0.65;
				m_mana = 80;
				break;
			case TROLL:
				m_life=150;
				m_atk=4;
				m_shield=1;
				m_shieldMax = 0.9;
				m_mana = 80;
				break;
		}

		m_lifeMax = m_life;
	}

	Entity::Entity(std::string name, Category type, int stage) : m_name(name), m_type(type) {
		switch(m_type) {
			case GOBLIN:
				m_life=50 + stage * 10;
				m_atk=3 + stage * 1;
				m_shield=1;
				m_shieldMax = 0.65 - stage * 0.05;
				break;
			case TROLL:
				m_life=150 + stage * 15;
				m_atk=8 + stage * 2;
				m_shield=1;
				m_shieldMax = 0.9 - stage * 0.05;
				break;
		}

		m_lifeMax = m_life;
		m_mana = 80;
	}

	Entity::Entity(int life, std::string name, int shield, int atk, Category type) : m_life(life), m_name(name), m_shield(shield), m_atk(atk), m_type(type) {}

	Entity::~Entity() {};

	void Entity::giveDmg(Entity& cible) const{
		cible.takeDmg(m_atk);
	}

	void Entity::takeDmg(int atk) {
		m_life = m_life - (atk * m_shield);
		if (m_life < 0) {
			m_life = 0;
		}

		m_shield = 1;
	}

	bool Entity::isDead() const {
		return m_life == 0;
	}

	void Entity::heal(){
		
		if (m_mana >= 80) {
			m_life += m_lifeMax * 0.5;

			if (m_life > m_lifeMax) {
				m_life = m_lifeMax;
			}
			m_mana -= 80;
		}
	}

	// get functions 

	std::string Entity::getName() const{
		return m_name;
	}

	int Entity::getLife()  const{
		return m_life;
	}

	int Entity::getLifeMax() const{
		return m_lifeMax;
	}

	int Entity::getAtk() const{
		return m_atk;
	}
	

	double Entity::getShield() const{
		return m_shield;
	}

	int Entity::getType() const{
		return m_type;
	}
	
	int Entity::getMana() const {
		return m_mana;
	}

	void Entity::setMana(int mana) {
		m_mana += mana;
	}
		
}