#include "knight.hpp"

namespace JeuConsole {
	Knight::Knight(int life, std::string name, int atk, int shield) {
		m_life = 100;
		m_name = name;
		m_shield = 75;
		m_atk = 12;
	}
	
	Knight::~Knight();

}

