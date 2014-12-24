#include "HeroMgr.h"
#include "PosLoadUtil.h"

HeroMgr::HeroMgr()
{
}

HeroMgr::~HeroMgr()
{
}


HeroMgr *HeroMgr::createWithLevel(int level)
{
	HeroMgr *hmgr = new HeroMgr();
	if(hmgr && hmgr->initWithLevel(level))
	{
		hmgr->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(hmgr);
	}

	return hmgr;
}

bool HeroMgr::initWithLevel(int level)
{
	createTowerPos(level);
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	//
	listener->onTouchBegan=[](Touch *touch, Event *event){return true;};
	listener->onTouchMoved=[](Touch *touch, Event *event){};
	listener->onTouchEnded=[=](Touch *touch, Event *event)
	{
		auto touchPos = touch->getLocationInView();
		auto pos = Director::getInstance()->convertToUI(touchPos);
		CCLOG("touch hero(tower): x=%f, y=%f\n", pos.x, pos.y);
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);

	return true;
}

void HeroMgr::createTowerPos(int level)
{
	__String *towerPath = __String::createWithFormat("game/tower_level_%d.plist", level);
	PosLoadUtil::getInstance()->loadPosWithFile(towerPosList, enTowerPos, towerPath->getCString(), this, level, true);
}

void HeroMgr::createTowerBorder()
{
	PosBase *tpos;
	for(auto ref : towerPosList)
	{
		tpos = dynamic_cast<PosBase *>(ref);
		if(tpos!=NULL)
		{
			TowerBorder *tborder = TowerBorder::create();
			tborder->setPosition(tpos->getPos());
			this->addChild(tborder);
			towerBorderList.pushBack(tborder);
		}
	}
}
