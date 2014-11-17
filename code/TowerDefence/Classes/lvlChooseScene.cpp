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
	auto visibleSize = Director::getInstance()->getVisibleSize();

	const char* norImg = "Button/choose_btn_nor.png";
	const char* lightImg = "Button/choose_btn_light.png"; 

	auto lvl_1_Item = MenuItemImage::create(norImg, lightImg, CC_CALLBACK_1(lvlChooseScene::lvl1, this));
	lvl_1_Item->addChild(createLvlLabel("lelve 1"));

	auto lvl_2_Item = MenuItemImage::create(norImg, lightImg, CC_CALLBACK_1(lvlChooseScene::lvl2, this));
	lvl_2_Item->addChild(createLvlLabel("lelve 2"));

	auto lvl_3_Item = MenuItemImage::create(norImg, lightImg, CC_CALLBACK_1(lvlChooseScene::lvl3, this));
	lvl_3_Item->addChild(createLvlLabel("lelve 3"));

	auto menu = CCMenu::create(lvl_1_Item, lvl_2_Item, lvl_3_Item, nullptr);
	menu->alignItemsHorizontallyWithPadding(20);
	menu->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));

	this->addChild(menu);
	return true;
}


Label* lvlChooseScene::createLvlLabel(const char *lvlstr)
{
	auto lvlLable = Label::create(lvlstr, "Arial", 60);
	lvlLable->setColor(Color3B::RED);
	lvlLable->setPosition(ccp(60, 60));//Button size is 130x130
	return lvlLable;
}


void lvlChooseScene::lvl1(Ref *pSender)
{
	CCLOG("level 1");
}

void lvlChooseScene::lvl2(Ref *pSender)
{
	CCLOG("level 2");
}

void lvlChooseScene::lvl3(Ref *pSender)
{
	CCLOG("level 3");
}
