#include "lvlChooseScene.h"

lvlChooseScene::lvlChooseScene()
{
}

lvlChooseScene::~lvlChooseScene()
{
}

Scene *lvlChooseScene::createScene()
{
	auto scene = Scene::create();
	auto lvlScene = lvlChooseScene::create();// create() function defined at CREATE_FUNC()	
	scene->addChild(lvlScene);

	return scene;
}


bool lvlChooseScene::init()//create() function will call init()
{
	_lvl = 1;

	return true;
}


