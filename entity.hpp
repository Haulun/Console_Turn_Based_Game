#ifndef DEF_ENTITY
#define DEF_ENTITY

//std
#include <string>
#include <cstdlib>
#include <memory>


class Entity {
public:
		
	//Constructors and Destructor
	Entity() = default;
	Entity(int atk, int mana, int m_lifeMax, double shieldMax, int xp, std::string type);
	~Entity() = default;

	//Basic actions
	void giveDamage(Entity &aim) const;
	void absorbDamage();
	void heal();
	void resetShield();

	//All that an object can take	
	void takeDamage(int atk);
	bool takeXp(std::unique_ptr<Entity> &entity);

	//For levelUp
	void levelUp(std::string choice);
	void incLifeMax(int bonusLife);
	void incShieldMax(double bonusShield);
	void incAtk(int bonusAtk);
	void incMana(int bonusMana);


	//Can the object ... ?
	bool isDead();

	bool healable();

	//Getters
	int getXp() const; 
	int getLife() const;
	int getAtk() const;
	double getShield() const;
	int getMana() const;
	int getLevel() const;
	std::string getType() const;


protected:
	int m_life;
	double m_shield;
	int m_atk;
	int m_mana;
	int m_lifeMax;
	double m_shieldMax;
	int m_xp;
	int m_level;
	int m_manaMax;
	std::string m_type;
	};

#endif