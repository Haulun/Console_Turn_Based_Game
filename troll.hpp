#ifndef DEF_TROLL
#define DEF_TROLL

#include <string>
#include "enemy.hpp"

namespace JeuConsole {
	class Troll : public Enemy {
	public:
		Troll(std::string name);
		virtual void absorbDmg();
		/*virtual int getXp() const;*/
	};
}
#endif