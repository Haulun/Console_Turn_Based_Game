#ifndef DEF_ENTITY
#define DEF_ENTITY

#include <string>
#include <cstdlib>

namespace JeuConsole {
	enum Category { KNIGHT = 0, MAGE, GOBLIN, TROLL };


	class Entity {
	public:
		Entity(std::string name, Category type);
		Entity(std::string name, Category type, int stage);
		Entity(int life, std::string name, int shield, int atk, Category type);
		~Entity();
		void giveDmg(Entity& cible) const;
		void takeDmg(int atk);
		virtual void absorbDmg() {}
		bool isDead() const;
		void heal();

		//Hero function
		virtual void incLife() {}
		virtual void incShield() {}
		virtual void incAtk() {}
		virtual int getXp() const = 0;
		virtual bool takeXp(int xp) { return false; }
		virtual int getLevel() const = 0;
		virtual bool healable() {return true;}

		//Enemy function
		virtual int getGiveXp() const { return 0; }

		// get functions
		std::string getName() const;
		int getLife() const;
		int getLifeMax() const;
		int getAtk() const;
		double getShield() const;
		int getType() const;
		int getMana() const;

		// set functions
		void setShield(int shield);

		// inc functions
		void incMana(int mana);

	protected:
		int m_life;
		std::string m_name;
		double m_shield;
		int m_atk;
		int m_type;
		int m_lifeMax;
		double m_shieldMax;
		int m_mana;
		int m_manaMax;
	};
}
#endif