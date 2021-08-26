#ifndef DEF_TROLL
#define DEF_TROLL

#include <string>
#include "entity.hpp"

namespace JeuConsole {
	class Troll : public Entity {
	public:
		Troll(std::string name);
	};
}
#endif