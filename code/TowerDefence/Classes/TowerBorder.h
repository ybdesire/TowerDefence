#ifndef _TOWERBORDER_H_
#define _TOWERBORDER_H_

#include "cocos2d.h"
#include "Entity.h"
#include "Hero.h"

using namespace cocos2d;

class TowerBorder: public Entity
{
public:
	CREATE_FUNC(TowerBorder);
	virtual bool init();

	bool isClickMe(Point pos);

	Hero *getHero();

	void bindHero(Hero *phero);

private:
	Hero *_hero;
};


#endif