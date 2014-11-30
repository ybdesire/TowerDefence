#include "PosEditorLayer.h"
#include "PosBase.h"
#include "PosLoadUtil.h"

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
	//add map(BG image)
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto sBG = __String::createWithFormat("game/level_%d.jpg", _currentLevel);
	auto mapBg = Sprite::create(sBG->getCString());
	mapBg->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
	mapBg->setOpacity(150);
	this->addChild(mapBg);

	//add monster & tower
	auto monsterFilePath = __String::createWithFormat("game/monster_level_%d.plist",_currentLevel);
	auto towerFilePath = __String::createWithFormat("game/tower_level_%d.plist",_currentLevel);

	PosLoadUtil::getInstance()->loadPosWithFile(monsterPoBaseList, enMonsterPos, monsterFilePath->getCString(), this, _currentLevel, true);
	PosLoadUtil::getInstance()->loadPosWithFile(towerPoBaseList, enTowerPos, towerFilePath->getCString(), this, _currentLevel, true);

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
	if(_posType==enTowerPos)
	{
		_posType=enMonsterPos;
	}
	else
	{
		_posType=enTowerPos;
	}
}

void PosEditorLayer::editNextLevel()
{
	if(_currentLevel==3)
	{
		return;
	}

	_currentLevel++;
	deleteAllPB();
	preLoad();

	CCLOG("edit next level");
}

void PosEditorLayer::editPreLevel()
{
	if(_currentLevel==1)
	{
		return;
	}

	_currentLevel--;
	deleteAllPB();
	preLoad();
	CCLOG("edit previous level");
}

void PosEditorLayer::outPutToPositionListFile()
{
	String *monsterListFilePath = String::createWithFormat("game/monster_level_%d.plist", _currentLevel);
	String *towerListFilePath = String::createWithFormat("game/tower_level_%d.plist", _currentLevel);

	PosLoadUtil::getInstance()->writePBlistToFile(monsterPoBaseList, monsterListFilePath->getCString());
	PosLoadUtil::getInstance()->writePBlistToFile(towerPoBaseList, towerListFilePath->getCString());

	CCLOG("output");
}

void PosEditorLayer::deleteAllPB()
{
	this->removeAllChildrenWithCleanup(true);//remote all children from PosEditorLayer(even the bg)
	towerPoBaseList.clear();
	monsterPoBaseList.clear();
}

