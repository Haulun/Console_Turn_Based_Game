#include "entity.hpp"

Entity::Entity(int atk, int manaMax, int lifeMax, double shieldMax, int xp) : 
m_life(lifeMax), m_shield(1.0), m_atk(atk), m_mana(manaMax), m_lifeMax(lifeMax), m_shieldMax(shieldMax), m_xp(xp), m_level(0),  m_manaMax(manaMax) {}

void Entity::giveDamage(Entity& aim) const {
	aim.takeDamage(m_atk);
}

void Entity::absorbDamage() {
	m_shield = m_shieldMax;
}

void Entity::heal() {
	m_life += (int)(m_lifeMax / 2);
	m_mana -= 80;
	if (m_life > m_lifeMax) {
		m_life = m_lifeMax;
	}
}

void Entity::takeDamage(int atk) {
	m_life -= (int)(atk * m_shield);
	m_shield = 1.0;

	if (m_life < 0) {
		m_life = 0;
	}
}

bool Entity::takeXp(std::unique_ptr<Entity> &entity) {
	m_xp += entity->getXp();
	if (m_xp >= 50 + m_level * 25) {
		m_xp -= 50 + m_level * 25;
		m_level += 1;
		return true;
	}
	else {
		return false;
	}
}

//For levelUp :

void Entity::levelUp(std::string choice) {
	if (choice == "life") {
		incLifeMax(10);
	}
	else if (choice == "shield") {
		incShieldMax(0.05);
	}
	else if (choice == "attack") {
		incAtk(2);
	}
}

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
		this->~Entity();
		return true;
	}
	else {
		return false;
	}
}

bool Entity::healable() {
	return m_life <= m_lifeMax / 2 && m_mana >= 80;
}


void Entity::resetShield() {
	m_shield = 1.0;
}

//Getters :

int Entity::getXp() const {
	return m_xp;
}

int Entity::getLife() const {
	return m_life;
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

