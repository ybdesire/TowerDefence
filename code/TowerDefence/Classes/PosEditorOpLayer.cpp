#include "PosEditorOpLayer.h"


PosEditorOpLayer::PosEditorOpLayer():
	_editorLayer(NULL)
{
}

PosEditorOpLayer::~PosEditorOpLayer()
{
	CC_SAFE_RELEASE(_editorLayer);
}

PosEditorOpLayer *PosEditorOpLayer::create(PosEditorLayer *layer)
{
	auto oplayer = new PosEditorOpLayer();
	
	if(oplayer && oplayer->init(layer))
	{
		oplayer->autorelease();
	}
	else
	{
		CC_SAFE_RELEASE(oplayer);
	}

	return oplayer;
}

bool PosEditorOpLayer::init(PosEditorLayer *layer)
{
	if (!Layer::init())
	{
		return false;
	}
	CC_SAFE_RETAIN(layer);
	_editorLayer = layer;

	addControls();

	return true;
}

void PosEditorOpLayer::addControls()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	addOutPutCtr(visibleSize);
	addPBTypeChgCtr(visibleSize);
}

void PosEditorOpLayer::addOutPutCtr(Size visibleSize)
{
	auto btnTitle = Label::create("output", "Arial", 30);
	auto norSprite = Scale9Sprite::create("Button/public_ui_blue_btn.png");
	auto hlSprite = Scale9Sprite::create("Button/public_ui_green_btn.png");

	auto outputBtn = ControlButton::create(btnTitle, norSprite);
	outputBtn->setBackgroundSpriteForState(hlSprite, Control::State::HIGH_LIGHTED);
	outputBtn->setPosition(visibleSize.width-norSprite->getContentSize().width/2,
		norSprite->getContentSize().height);

	outputBtn->addTargetWithActionForControlEvents(
		this,
		cccontrol_selector(PosEditorOpLayer::outputPosToPlistFile),
		Control::EventType::TOUCH_UP_INSIDE
		);

	this->addChild(outputBtn);
}

void PosEditorOpLayer::outputPosToPlistFile(Ref* pSender,Control::EventType event)
{
	_editorLayer->outPutToPositionListFile();
}


void PosEditorOpLayer::addPBTypeChgCtr(Size visibleSize)
{
	auto btnTitle = Label::create("Change Type", "Arial", 30);
	auto norSprite = Scale9Sprite::create("Button/public_ui_blue_btn.png");
	auto hlSprite = Scale9Sprite::create("Button/public_ui_green_btn.png");

	auto chgTypeBtn = ControlButton::create(btnTitle, norSprite);
	chgTypeBtn->setBackgroundSpriteForState(hlSprite, Control::State::HIGH_LIGHTED);
	chgTypeBtn->setPosition(visibleSize.width-norSprite->getContentSize().width/2,
		norSprite->getContentSize().height*4);

	chgTypeBtn->addTargetWithActionForControlEvents(
		this,
		cccontrol_selector(PosEditorOpLayer::changePosBaseType),
		Control::EventType::TOUCH_UP_INSIDE
		);

	this->addChild(chgTypeBtn);

}

void PosEditorOpLayer::changePosBaseType(Ref* pSender,Control::EventType event)
{
	_editorLayer->changePBType();
}