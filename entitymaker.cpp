#include "entitymaker.hpp"

std::unique_ptr<Entity> EntityMaker::makeTroll(int const stage) {
	atk = 8 + stage * 2;
	manaMax = 80;
	lifeMax = 150 + stage * 15;
	shieldMax = 0.9 - stage * 0.05;
	xp = 30 + stage * 20;

	return std::make_unique<Entity>(atk, manaMax, lifeMax, shieldMax, xp);
}

std::unique_ptr<Entity> EntityMaker::makeGoblin(int const stage) {
	atk = 3 + stage * 1;
	manaMax = 80;
	lifeMax = 50 + stage * 10;
	shieldMax = 0.65 - stage * 0.05;
	xp = 10 + stage * 10;

	return std::make_unique<Entity>(atk, manaMax, lifeMax, shieldMax, xp);
}

std::unique_ptr<Entity> EntityMaker::makeKnight() {
	atk = 15;
	manaMax = 80;
	lifeMax = 100;
	shieldMax = 0.6;
	xp = 0;

	return std::make_unique<Entity>(atk, manaMax, lifeMax, shieldMax, xp);
}

std::unique_ptr<Entity> EntityMaker::makeWizard() {
	atk = 12;
	manaMax = 120;
	lifeMax = 80;
	shieldMax = 0.6;
	xp = 0;

	return std::make_unique<Entity>(atk, manaMax, lifeMax, shieldMax, xp);
}