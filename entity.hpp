#ifndef DEF_ENTITY
#define DEF_ENTITY

#include <string>
#include <cstdlib>

namespace JeuConsole {
	enum Category { KNIGHT = 0, MAGE, GOBLIN, TROLL };


	class Entity {
	public:
		Entity(std::string name, Category type);
		Entity(int life, std::string name, int shield, int atk, Category type);
		~Entity();
		void giveDmg(Entity& cible) const;
		void takeDmg(int atk);
		virtual void absorbDmg() {};
		bool isDead() const;
		

		std::string getName() const;
		int getLife() const;
		int getAtk() const;
		double getShield() const;
		int getType() const;



	protected:
		int m_life;
		std::string m_name;
		double m_shield;
		int m_atk;
		int m_type;
	};
}
#endif