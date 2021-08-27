#ifndef DEF_HERO
#define DEF_HERO

#include <string>
#include <cstdlib>

#include "entity.hpp"

namespace JeuConsole {

	class Hero : public Entity {
	public:
		Hero(std::string name, Category type);
		~Hero(){}

		int getXp() const;

		void takeXp(int xp);

	protected:
		int m_xp;
	};
}
#endif