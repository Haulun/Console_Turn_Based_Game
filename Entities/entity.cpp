#include "entity.hpp"

Entity::Entity() {}

Entity::Entity(std::string name, int atk, int manaMax, int lifeMax, double shieldMax, int xp) {
	m_name = name;
	m_atk = atk;
	m_manaMax = manaMax;
	m_lifeMax = lifeMax;
	m_shieldMax = shieldMax;
	m_xp = xp;

	m_life = m_lifeMax;
	m_shield = 1;
	m_level = 0;
	m_mana = m_manaMax;
}


Entity::~Entity() {

}

void Entity::giveDamage(Entity& aim) const {
	aim.takeDamage(m_atk);
}

void Entity::absorbDamage() {
	m_shield = m_shieldMax;
}

bool Entity::heal() {
	if (m_mana >= 80) {
		m_life += (int)(m_lifeMax / 0.5);
		m_mana -= 80;
		if (m_life > m_lifeMax) {
			m_life = m_lifeMax;
		}
		return true;
	}
	else {
		return false;
	}
}

void Entity::takeDamage(int atk) {
	m_life -= (int)(atk * m_shield);
	m_shield = 1.0;

	if (m_life < 0) {
		m_life = 0;
	}
}

bool Entity::takeXp(int xp) {
	if (m_xp >= 100 + m_level * 100) {
		m_xp -= 100 + m_level * 100;
		m_level += 1;
		return true;
	}
	else {
		m_xp += xp;
		return false;
	}
}

//Incrementations :

void Entity::incLifeMax(int bonusLife) {
	m_lifeMax += bonusLife;
	m_life = m_lifeMax;
}

void Entity::incShieldMax(double bonusShield) {
	m_shieldMax -= bonusShield;
}

void Entity::incAtk(int bonusAtk) {
	m_atk += bonusAtk;
}

void Entity::incMana(int bonusMana) {
	m_mana += bonusMana;

	if (m_mana > m_manaMax) {
		m_mana = m_manaMax;
	}
}

bool Entity::isDead() {
	if (m_life == 0) {
		return true;
	}
	else {
		return false;
	}
}

//Getters :

int Entity::getXp() const {
	return m_xp;
}

std::string Entity::getName() const {
	return m_name;
}

int Entity::getLife() const {
	return m_life;
}

int Entity::getLifeMax() const {
	return m_lifeMax;
}

int Entity::getAtk() const {
	return m_atk;
}
double Entity::getShield() const {
	return m_shield;
}

int Entity::getMana() const {
	return m_mana;
}

int Entity::getLevel() const{
	return m_level;
}

//Setters :
void Entity::setShield(double newShield) {
	m_shield = newShield;
}











































	//Entity::Entity(std::string name, Category type) : m_name(name), m_type(type) {
	//	switch(m_type) {
	//		case KNIGHT:
	//			m_life=100;
	//			m_atk=12;
	//			m_shield=1;
	//			m_shieldMax = 0.5;
	//			m_mana = 90;
	//			break;
	//		case MAGE:
	//			m_life=90;
	//			m_atk=13;
	//			m_shield=1;
	//			m_shieldMax = 0.3;
	//			m_mana = 100;
	//			break;
	//		case GOBLIN:
	//			m_life=50;
	//			m_atk=3;
	//			m_shield=1;
	//			m_shieldMax = 0.65;
	//			m_mana = 80;
	//			break;
	//		case TROLL:
	//			m_life=150;
	//			m_atk=4;
	//			m_shield=1;
	//			m_shieldMax = 0.9;
	//			m_mana = 80;
	//			break;
	//	}

	//	m_lifeMax = m_life;
	//	m_manaMax = m_mana;
	//}

	//Entity::Entity(std::string name, Category type, int stage) : m_name(name), m_type(type) {
	//	switch(m_type) {
	//		case GOBLIN:
	//			m_life=50 + stage * 10;
	//			m_atk=3 + stage * 1;
	//			m_shield=1;
	//			m_shieldMax = 0.65 - stage * 0.05;
	//			break;
	//		case TROLL:
	//			m_life=150 + stage * 15;
	//			m_atk=8 + stage * 2;
	//			m_shield=1;
	//			m_shieldMax = 0.9 - stage * 0.05;
	//			break;
	//	}

	//	m_lifeMax = m_life;
	//	m_mana = 80;
	//}

	//Entity::Entity(int life, std::string name, int shield, int atk, Category type) : m_life(life), m_name(name), m_shield(shield), m_atk(atk), m_type(type) {}

	//Entity::~Entity() {};

	//void Entity::giveDmg(Entity& cible) const{
	//	cible.takeDmg(m_atk);
	//}

	//void Entity::takeDmg(int atk) {
	//	m_life = m_life - (atk * m_shield);
	//	if (m_life < 0) {
	//		m_life = 0;
	//	}

	//	m_shield = 1;
	//}

	//bool Entity::isDead() const {
	//	return m_life == 0;
	//}

	//void Entity::heal(){
	//	
	//	if (m_mana >= 80) {
	//		m_life += m_lifeMax * 0.5;

	//		if (m_life > m_lifeMax) {
	//			m_life = m_lifeMax;
	//		}
	//		m_mana -= 80;
	//	}
	//}

	//// Get functions 

	//std::string Entity::getName() const{
	//	return m_name;
	//}

	//int Entity::getLife()  const{
	//	return m_life;
	//}

	//int Entity::getLifeMax() const{
	//	return m_lifeMax;
	//}

	//int Entity::getAtk() const{
	//	return m_atk;
	//}
	//

	//double Entity::getShield() const{
	//	return m_shield;
	//}

	//int Entity::getType() const{
	//	return m_type;
	//}
	//
	//int Entity::getMana() const {
	//	return m_mana;
	//}

	//// Set functions


	//void Entity::setShield(int shield) {
	//	m_shield = shield;
	//}

	//// Inc functions

	//void Entity::incMana(int mana) {
	//	m_mana += mana;
	//	if(m_mana > m_manaMax){
	//		m_mana = m_manaMax;
	//	}

	//}