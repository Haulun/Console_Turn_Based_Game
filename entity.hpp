#include <string>

namespace JeuConsole {
	class Entity {
	public:
		Entity(std::string name);
		Entity(int life, std::string name, int shield, int atk);
		~Entity();
		void giveDmg(Entity& cible);
		void takeDmg(int atk);
		bool isDead();
		std::string getName();
		int getLife();
	protected:
		int m_life;
		std::string m_name;
		int m_shield;
		int m_atk;
	};
}