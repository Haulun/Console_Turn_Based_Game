#ifndef DEF_MAGE
#define DEF_MAGE

#include <string>
#include "hero.hpp"

namespace JeuConsole {
	class Mage : public Hero {
	public:
		Mage(std::string name);
		virtual void absorbDmg();
	};
}
#endif