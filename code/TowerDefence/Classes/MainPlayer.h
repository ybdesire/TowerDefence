#ifndef _MAINPLAYER_H_
#define _MAINPLAYER_H_

#include "cocos2d.h"
#include "HeroMgr.h"

using namespace cocos2d;

class MainPlayer: public Layer
{
public:
	MainPlayer();
	~MainPlayer();
	static MainPlayer *create(int level);
	virtual bool init(int level);

private:
	int currentLevel;

	HeroMgr *currentHero;

	void preLoad();
};

#endif