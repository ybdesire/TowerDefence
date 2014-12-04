#ifndef _HERO_H_
#define _HERO_H_

#include "cocos2d.h"
#include "Entity.h"

using namespace cocos2d;

class Hero: public Entity
{
public:
	static Hero* createHeroFromCsvFileByID(int heroID);
	virtual bool initHeroFromCsvFileByID(int heroID);
};

#endif