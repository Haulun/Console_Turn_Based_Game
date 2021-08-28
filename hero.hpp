#ifndef DEF_HERO
#define DEF_HERO

//std
#include <string>
#include <cstdlib>

#include "entity.hpp"

namespace JeuConsole {

	class Hero : public Entity {
	public:
		Hero(std::string name, Category type);
		~Hero(){}
		
		void levelUp();

		virtual int getXp() const;
		virtual int getLevel() const;
		virtual bool takeXp(int xp);
		virtual void incLife();
		virtual void incShield();
		virtual void incAtk();
		virtual bool healable();

	protected:
		int m_xp = 0;
		int m_xpMax = 50;
		int m_level = 0;
	};
}
#endif