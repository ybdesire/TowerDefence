#include "GetBackLayer.h"
#include "MainScene.h"

GetBackLayer::GetBackLayer()
{
}

GetBackLayer::~GetBackLayer()
{
}

bool GetBackLayer::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	
	auto btnTitle = Label::create("Back","Arial",30);
	auto norBtnSprite = Scale9Sprite::create("Button/public_ui_blue_btn.png");
	auto highlightBtnSprite = Scale9Sprite::create("Button/public_ui_green_btn.png");

	auto getBackBtn = ControlButton::create(btnTitle, norBtnSprite);
	getBackBtn->setBackgroundSpriteForState(highlightBtnSprite, Control::State::HIGH_LIGHTED);
	getBackBtn->setPosition(visibleSize.width - norBtnSprite->getContentSize().width/2, visibleSize.height/2 - norBtnSprite->getContentSize().height);

	getBackBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(GetBackLayer::getBack), Control::EventType::TOUCH_UP_INSIDE);

	this->addChild(getBackBtn, 20);

	return true;
}


void GetBackLayer::getBack(Ref *pSender, Control::EventType event)
{
	auto scene = MainScene::createScene();
	Director::getInstance()->replaceScene(scene);
}