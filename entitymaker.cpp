#include "entitymaker.hpp"

std::unique_ptr<Entity> EntityMaker::makeTroll(int const stage) {
	m_atk = 8 + stage * 2;
	m_manaMax = 80;
	m_lifeMax = 150 + stage * 15;
	m_shieldMax = 0.9 - stage * 0.05;
	m_xp = 30 + stage * 20;
	m_type = "creature";

	return std::make_unique<Entity>(m_atk, m_manaMax, m_lifeMax, m_shieldMax, m_xp, m_type);
}

std::unique_ptr<Entity> EntityMaker::makeGoblin(int const stage) {
	m_atk = 3 + stage * 1;
	m_manaMax = 80;
	m_lifeMax = 50 + stage * 10;
	m_shieldMax = 0.65 - stage * 0.05;
	m_xp = 10 + stage * 10;
	m_type = "creature";

	return std::make_unique<Entity>(m_atk, m_manaMax, m_lifeMax, m_shieldMax, m_xp, m_type);
}

std::unique_ptr<Entity> EntityMaker::makeKnight() {
	m_atk = 15;
	m_manaMax = 80;
	m_lifeMax = 100;
	m_shieldMax = 0.6;
	m_xp = 0;
	m_type = "hero";

	return std::make_unique<Entity>(m_atk, m_manaMax, m_lifeMax, m_shieldMax, m_xp, m_type);
}

std::unique_ptr<Entity> EntityMaker::makeWizard() {
	m_atk = 12;
	m_manaMax = 120;
	m_lifeMax = 90;
	m_shieldMax = 0.6;
	m_xp = 0;
	m_type = "hero";

	return std::make_unique<Entity>(m_atk, m_manaMax, m_lifeMax, m_shieldMax, m_xp, m_type);
}

std::unique_ptr<Entity> EntityMaker::makeDragon() {
	m_atk = 25;
	m_manaMax = 0;
	m_lifeMax = 500;
	m_shieldMax = 0.1;
	m_xp = 0;
	m_type = "boss";

	return std::make_unique<Entity>(m_atk, m_manaMax, m_lifeMax, m_shieldMax, m_xp, m_type);
}
