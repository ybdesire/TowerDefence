#include "PosEditorLayer.h"
#include "PosBase.h"

PosEditorLayer::PosEditorLayer()
{
	_currentLevel = 2;
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
	auto posBase = PosBase::create(pos, _posType, true);
	this->addChild(posBase);
}