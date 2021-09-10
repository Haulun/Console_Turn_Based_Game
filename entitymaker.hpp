#ifndef DEF_ENTITYMAKER
#define DEF_ENTITYMAKER

#include "entity.hpp"

class EntityMaker {
public:

	~EntityMaker() = default;
	
	std::unique_ptr<Entity> makeTroll(int const stage);
	std::unique_ptr<Entity> makeGoblin(int const stage);
	std::unique_ptr<Entity> makeKnight();
	std::unique_ptr<Entity> makeWizard();
	std::unique_ptr<Entity> makeDragon();
private:
	int m_atk = 0;
	int m_manaMax = 0;
	int m_lifeMax = 0;
	double m_shieldMax = .0;
	int m_xp = 0;
};
#endif