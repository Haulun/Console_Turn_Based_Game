#ifndef DEF_ENTITY
#define DEF_ENTITY

#include <string>
#include <cstdlib>

	
enum class Type {
	TROLL,
	GOBLIN,
	KNIGHT,
	WIZARD
};

class Entity {
public:
		
	//Constructeur et destructeur basiques

	Entity();
	Entity(Type type);
	~Entity();

	//Actions basiques

	void giveDamage(Entity &aim) const;
	bool absorbDamage(/*???*/);
	bool heal();

	//Tout ce qui peut être pris par l'objet
		
	void takeDamage(int atk);
	void takeXp(int xp);

	//Salut

	void levelUp(Entity& donor);
	int getXp() const;

	//L'objet peut-il être détruit ?

	bool isDead();

protected:
	std::string m_name = "NONAME";
	int m_life = 100;
	double m_shield = 0;
	int m_atk = 10;
	int m_mana = 100;
	int m_lifeMax = 100;
	double m_shieldMax = 0;
	int m_xp = 0;







































		
	



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
	//	std::string getName() const;
	//	int getLife() const;
	//	int getLifeMax() const;
	//	int getAtk() const;
	//	double getShield() const;
	//	int getType() const;
	//	int getMana() const;

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