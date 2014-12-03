#include "GameScene.h"
#include "MainPlayer.h"
#include "GetBackLayer.h"


Scene *GameScene::create(int level)
{
	auto scene = Scene::create();
	MainPlayer *lvl2Player = MainPlayer::create(2);
	scene->addChild(lvl2Player);
	
	auto backlayer = GetBackLayer::create();
	scene->addChild(backlayer);

	return scene;
}