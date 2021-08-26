#ifndef DEF_GOBLIN
#define DEF_GOBLIN

#include <string>
#include "entity.hpp"

namespace JeuConsole {
	class Goblin : public Entity {
	public:
		Goblin(std::string name);
		virtual void absorbDmg();
	};
}
#endif