#ifndef DEF_ENTITY
#define DEF_ENTITY

#include <string>

namespace JeuConsole {
	enum Category { KNIGHT = 0, MAGE, GOBLIN, TROLL };


	class Entity {
	public:
		Entity(std::string name, Category type);
		Entity(int life, std::string name, int shield, int atk, Category type);
		~Entity();
		void giveDmg(Entity& cible);
		void takeDmg(int atk);
		bool isDead();
		

		std::string getName();
		int getLife();
		int getAtk();
		int getShield();
		int getType();



	protected:
		int m_life;
		std::string m_name;
		int m_shield;
		int m_atk;
		int m_type;
	};
}
#endif