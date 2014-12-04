#include "Hero.h"

Hero *Hero::createHeroFromCsvFileByID(int heroID)
{
	Hero *hero = new Hero();
	if(hero && hero->initHeroFromCsvFileByID(heroID))
	{
		hero->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(hero);
	}

	return hero;
}

bool Hero::initHeroFromCsvFileByID(int heroID)
{
	auto heroSprite = Sprite::create(__String::createWithFormat("sprite/hero/hero_%d.png", heroID)->getCString());
	bindSprite(heroSprite);
	return true;
}