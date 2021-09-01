#ifndef DEF_ENTITY
#define DEF_ENTITY

#include <string>
#include <cstdlib>

class Entity {
public:
		
	//Constructors and Destructor
	Entity();
	Entity(std::string name, int atk, int mana, int m_lifeMax, double shieldMax, int xp);
	~Entity();

	//Basic actions
	void giveDamage(Entity &aim) const;
	void absorbDamage();
	bool heal();

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
	std::string getName() const;
	int getLife() const;
	int getLifeMax() const;
	int getAtk() const;
	double getShield() const;
	int getMana() const;
	int getLevel() const;

	//Setters
	void setShield(double newShield);


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







































		
	



	//enum Type { KNIGHT = 0, MAGE, GOBLIN, TROLL };


	//	//Hero function
	//	virtual void incLife() {}
	//	virtual void incShield() {}
	//	virtual void incAtk() {}
	//	virtual int getXp() const = 0;
	//	virtual bool takeXp(int xp) { return false; }
	//	virtual int getLevel() const = 0;
	//	virtual bool healable() {return true;}

	//	//Enemy function
	//	virtual int getGiveXp() const { return 0; }

	//	// get functions
	

	//	// set functions
	//	void setShield(int shield);

		//VOIR SOLID

	//	// inc functions
	//	void incMana(int mana);

	//protected:
	//	int m_life;
	//	std::string m_name;
	//	double m_shield;
	//	int m_atk;
	//	int m_type;
	//	int m_lifeMax;
	//	double m_shieldMax;
	//	int m_mana;
	//	int m_manaMax;
	};

#endif