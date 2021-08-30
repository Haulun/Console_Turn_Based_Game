#ifndef DEF_TROLL
#define DEF_TROLL

#include <string>
#include "enemy.hpp"

namespace JeuConsole {
	class Troll : public Enemy {
	public:
		Troll(std::string name, int level);
		virtual void absorbDmg();
	};
}
#endif