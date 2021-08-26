#ifndef DEF_MAGE
#define DEF_MAGE

#include <string>
#include "entity.hpp"

namespace JeuConsole {
	class Mage : public Entity {
	public:
		Mage(std::string name);
		virtual void absorbDmg();
	};
}
#endif