#include "PosEditorLayer.h"
#include "PosBase.h"

PosEditorLayer::PosEditorLayer()
{
	_currentLevel = 1;
	_posType = enTowerPos;
}

PosEditorLayer::~PosEditorLayer()
{
}


bool PosEditorLayer::init()
{
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = [](Touch *touch, Event *event)
	{
		return true;
	};

	listener->onTouchMoved = [](Touch *touch, Event *event)
	{
	};

	listener->onTouchEnded = [=](Touch *touch, Event *event)
	{
		auto touchPos = touch->getLocationInView();
		auto pos = Director::getInstance()->convertToUI(touchPos);

		CCLOG("Touch pos.X is %f, pos.Y is %f", pos.x, pos.y);

		editPos(pos);
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);

	preLoad();//load bg Sprite by level

	return true;
}


void PosEditorLayer::preLoad()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto sBG = __String::createWithFormat("game/level_%d.jpg", _currentLevel);
	auto mapBg = Sprite::create(sBG->getCString());
	mapBg->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
	mapBg->setOpacity(150);
	this->addChild(mapBg);
}


void PosEditorLayer::editPos(Point pos)
{
	auto posbase = findExistPos(pos);

	if(posbase)
	{
		deletePosBase(posbase);
	}
	else
	{
		createPos(pos);
	}
}

PosBase *PosEditorLayer::findExistPos(Point pos)
{
	Vector<PosBase*> posList;
	if(_posType==enTowerPos)
	{
		posList = towerPoBaseList;
	}
	else
	{
		posList = monsterPoBaseList;
	}

	for(auto ref:posList)
	{
		if(ref->isClickMe(pos))
			return ref;
	}
	return nullptr;
}

void PosEditorLayer::createPos(Point pos)
{
	auto posbase = PosBase::create(pos, _posType, true);
	this->addChild(posbase);

	if(_posType==enMonsterPos)
	{
		monsterPoBaseList.pushBack(posbase);
	}
	else if(_posType==enTowerPos)
	{
		towerPoBaseList.pushBack(posbase);
	}
}

void PosEditorLayer::deletePosBase(PosBase *posbase)
{
	this->removeChild(posbase);
	
		if(_posType==enMonsterPos)
	{
		monsterPoBaseList.eraseObject(posbase);
	}
	else if(_posType==enTowerPos)
	{
		towerPoBaseList.eraseObject(posbase);
	}
}

void PosEditorLayer::changePBType()
{
}

void PosEditorLayer::editNextLevel()
{
}

void PosEditorLayer::editPreLevel()
{
}

void PosEditorLayer::outPutToPositionListFile()
{
	CCLOG("output");
}