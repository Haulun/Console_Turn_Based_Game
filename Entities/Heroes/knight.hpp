#ifndef DEF_KNIGHT
#define DEF_KNIGHT

#include <string>
#include "hero.hpp"

namespace JeuConsole {
	class Knight : public Hero {
	public:
		Knight(std::string name);
		virtual void absorbDmg();
	};
}
#endif