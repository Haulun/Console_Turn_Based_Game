#include <string>
#include "entity.hpp"

namespace JeuConsole {
	class Knight : public Entity {
	public:
		Knight(int life, std::string name, int atk, int shield);
		~Knight();
	protected:
		int m_life;
		std::string m_name;
		int m_shield;
		int m_atk;
	};
}