#include "MainPlayer.h"

MainPlayer::MainPlayer():currentLevel(0), currentHero(NULL)
{
}

MainPlayer::~MainPlayer()
{
}

MainPlayer *MainPlayer::create(int level)
{
	auto mainplayer = new MainPlayer();
	if(mainplayer && mainplayer->init(level))
	{
		mainplayer->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(mainplayer);
	}
	return mainplayer;
}

bool MainPlayer::init(int level)
{
	currentLevel = level;
	preLoad();

	HeroMgr *hero = HeroMgr::createWithLevel(level);
	currentHero = hero;
	this->addChild(hero);

	return true;
}

void MainPlayer::preLoad()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	String *sbg = String::createWithFormat("game/level_%d.jpg", currentLevel);
	Sprite *bgmap = Sprite::create(sbg->getCString());
	bgmap->setOpacity(150);
	bgmap->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
	this->addChild(bgmap);
}