#ifndef DEF_ENEMY
#define DEF_ENEMY

#include <string>
#include <cstdlib>

#include "entity.hpp"

namespace JeuConsole {

	class Enemy : public Entity {
	public:
		Enemy(std::string name, Category type);
		~Enemy(){}

		virtual int getGiveXp() const;
		virtual int getXp() const;
		virtual int getLevel() const ;

	protected:
		int m_giveXp;
	};
}
#endif