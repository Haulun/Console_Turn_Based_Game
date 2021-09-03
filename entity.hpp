#ifndef DEF_ENTITY
#define DEF_ENTITY

//std
#include <string>
#include <cstdlib>


class Entity {
public:
		
	//Constructors and Destructor
	Entity() = default;
	Entity(int atk, int mana, int m_lifeMax, double shieldMax, int xp);
	~Entity() = default;

	//Basic actions
	void giveDamage(Entity &aim) const;
	void absorbDamage();
	bool heal();
	void resetShield();

	//All that an object can take	
	void takeDamage(int atk);
	bool takeXp(int xp);

	//Incrementations
	void incLifeMax(int bonusLife);
	void incShieldMax(double bonusShield);
	void incAtk(int bonusAtk);
	void incMana(int bonusMana);


	//Can the object be destroyed ?
	bool isDead();

	//Getters
	int getXp() const; 
	int getLife() const;
	int getLifeMax() const;
	int getAtk() const;
	double getShield() const;
	int getMana() const;
	int getLevel() const;



protected:
	std::string m_name = "NONAME";
	int m_life = 100;
	double m_shield = 0;
	int m_atk = 10;
	int m_mana = 100;
	int m_lifeMax = 100;
	double m_shieldMax = 0;
	int m_xp = 0;
	int m_level = 0;
	int m_manaMax = 100;
	};

#endif