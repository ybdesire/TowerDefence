#include "Entity.h"

Entity::Entity():
	_sprite(NULL), 
	_isDead(false),
	_id(0),
	_modeID(0),
	_entityName(__String::create("")),
	_hp(1),
	_defence(1),
	_speed(0),
	_level(1)
{
}

Entity::~Entity()
{
}

void Entity::bindSprite(Sprite *sprit)
{
	if(sprit != NULL)
	{
		if(_sprite!=NULL)
		{
			_sprite->removeFromParentAndCleanup(true);
		}
		_sprite = sprit;
		this->addChild(_sprite);

		//if the derived class need other bind
		onBindSprite();
	}
}

void Entity::hurtMe(int hurtValue)
{
}


bool Entity::isDead()
{
	return _isDead;
}


Rect Entity::boundingBox()
{
	Node::boundingBox();
	if(getSprite()==NULL)
	{
		return CCRectMake(0, 0, 0, 0);
	}
	Point pos = getPosition();
	Size size = getSprite()->getContentSize();

	return CCRectMake(pos.x, pos.y, size.width, size.height);
}


Sprite *Entity::getSprite()
{
	return this->_sprite;
}

void Entity::onDead()
{
}

void Entity::onBindSprite()
{
}

void Entity::onHurt(int hurtValue)
{
}