#ifndef DEF_GOBLIN
#define DEF_GOBLIN

#include <string>
#include "enemy.hpp"

namespace JeuConsole {
	class Goblin : public Enemy {
	public:
		Goblin(std::string name, int stage);
		virtual void absorbDmg();
	};
}
#endif