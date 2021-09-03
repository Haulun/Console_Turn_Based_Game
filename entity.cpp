#include "entity.hpp"

Entity::Entity(int atk, int manaMax, int lifeMax, double shieldMax, int xp) {
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
	if (m_xp >= 50 + m_level * 50) {
		m_xp -= 50 + m_level * 50;
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
	if (this != nullptr) {
		if (m_life == 0) {
			this->~Entity();
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return true;
	}
	
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

