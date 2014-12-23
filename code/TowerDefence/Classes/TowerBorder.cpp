#include "TowerBorder.h"


Hero *TowerBorder::getHero()
{
	return _hero;
}

void TowerBorder::bindHero(Hero *phero)
{
	_hero = phero;
}

bool TowerBorder::init()
{
	__String *sFilePath = __String::createWithFormat("sprite/hero/border_%d.png", _level);
	Sprite *sprite = Sprite::create(sFilePath->getCString());

	bindSprite(sprite);


	ActionInterval *rotateBy = RotateBy::create(25.0f, 360, 360);
	auto repeat = RepeatForever::create(rotateBy);

	sFilePath = __String::createWithFormat("sprite/hero/magic_border_%d.png", _level);
	sprite = Sprite::create(sFilePath->getCString());
	sprite->setOpacity(80);
	sprite->runAction(repeat);

	this->addChild(sprite);
	return true;
}

bool TowerBorder::isClickMe(Point pos)
{
	Size size = getSprite()->getContentSize();
	Point borderPos = getPosition();

	Point srcPos = Point(borderPos.x-size.width, borderPos.y+size.height);
	Point detPos = Point(borderPos.x+size.width, borderPos.y-size.height);

	if(pos.x>=srcPos.x && pos.y>=srcPos.y && pos.x<=detPos.x && pos.y<=detPos.y)
	{
		return true;
	}

	return false;
}