#include "TowerBorder.h"

bool TowerBorder::init()
{
	return true;
}

Hero *TowerBorder::getHero()
{
	return _hero;
}

void TowerBorder::bindHero(Hero *phero)
{
	_hero = phero;
}