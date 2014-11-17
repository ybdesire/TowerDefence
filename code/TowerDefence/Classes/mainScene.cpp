#include "MainScene.h"
#include "lvlChooseScene.h"
//#include "positionEditScene.h"

MainScene::MainScene()
{
}

MainScene::~MainScene()
{
}

Scene *MainScene::createScene()
{
	auto scene = Scene::create();
	auto layer = MainScene::create();//create() defined by CREATE_FUNC(), this func will call init()

	scene->addChild(layer);

	return scene;
}


bool MainScene::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();//get current visible size
	
	auto BG = Sprite::create("game/MainSceneBG.jpg");
	BG->setPosition(visibleSize.width/2,visibleSize.height/2);
	BG->setOpacity(200); //opacity: none
	this->addChild(BG);

	createChooseMenu();
	return true;
}

void MainScene::createChooseMenu()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	
	const char* norImg = "Button/choose_btn_nor.png";
	const char* lightImg = "Button/choose_btn_light.png";
	
	
	auto title = Label::create("Start","Arial",35);
	title->setPosition(ccp(60, 60));
	auto startItem = MenuItemImage::create(norImg, lightImg, CC_CALLBACK_1(MainScene::startGame,this));
	startItem->addChild(title);

	
    title = Label::create("Editor","Arial",35);
	title->setPosition(ccp(60, 60));
	auto editorItem = MenuItemImage::create(norImg, lightImg, CC_CALLBACK_1(MainScene::editorScene,this));
	editorItem->addChild(title);
	
	
	auto menu = CCMenu::create(startItem, editorItem, nullptr);
	
	menu->alignItemsVerticallyWithPadding(20);
	menu->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));

	this->addChild(menu);
}

void MainScene::editorScene(Ref *pSender)
{
	CCLOG("YB editor scene");
	//auto scene = positionEditScene::createScene();
	//Director::getInstance()->replaceScene(scene);
}

void MainScene::startGame(Ref *pSender)
{
	auto lvlChooseScene = lvlChooseScene::createScene();
	Director::getInstance()->replaceScene(lvlChooseScene);

	CCLOG("YB start Game");
}