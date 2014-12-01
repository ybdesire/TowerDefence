#ifndef _HEROMGR_H_
#define _HEROMGR_H_

#include "cocos2d.h"
#include "PosBase.h"

using namespace cocos2d;

class HeroMgr: public Layer
{
public:
	HeroMgr();
	~HeroMgr();
	static HeroMgr *createWithLevel(int level);
	virtual bool initWithLevel(int level);
	
private:
	Vector<PosBase *> towerPosList;
	void createTowerPos(int level);
};

#endif