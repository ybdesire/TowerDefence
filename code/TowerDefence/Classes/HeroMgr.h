#ifndef _HEROMGR_H_
#define _HEROMGR_H_

#include "cocos2d.h"
#include "PosBase.h"
#include "TowerBorder.h"

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
	Vector<TowerBorder *> towerBorderList;
	void createTowerPos(int level);

	void createTowerBorder();
	TowerBorder *findClickTowerBorder(Point pos);
};

#endif