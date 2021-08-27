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

		virtual int getXp() const;
		virtual int getLevel() const;

		virtual bool takeXp(int xp);
		void levelUp();

		virtual void incLife();
		virtual void incShield();
		virtual void incAtk();

	protected:
		int m_xp = 0;
		int m_xpMax = 100;
		int m_level = 0;
	};
}
#endif