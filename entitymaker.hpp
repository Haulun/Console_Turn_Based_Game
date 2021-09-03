#include "entity.hpp"

class EntityMaker {
public:

	~EntityMaker() = default;

	std::unique_ptr<Entity> makeTroll(int const stage);
	std::unique_ptr<Entity> makeGoblin(int const stage);
	std::unique_ptr<Entity> makeKnight();
	std::unique_ptr<Entity> makeWizard();
private:
	int atk = 0;
	int manaMax = 0;
	int lifeMax = 0;
	double shieldMax = 0;
	int xp = 0;
};