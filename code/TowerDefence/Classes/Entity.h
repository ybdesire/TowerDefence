#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "cocos2d.h"

using namespace cocos2d;

class Entity: public Node
{
public:
	Entity();
	~Entity();
	void bindSprite(Sprite *sprit);
	Sprite *getSprite();

	void hurtMe(int hurtValue);
	bool isDead();
	Rect boundingBox();

protected:
	virtual void onDead();
	virtual void onBindSprite();
	virtual void onHurt(int hurtValue);

private:
	Sprite *_sprite;
	bool _isDead;
	
	CC_SYNTHESIZE(int, _id, ID);
	CC_SYNTHESIZE(int, _modeID, ModeID);
	CC_SYNTHESIZE(__String *, _entityName, EntityName);
	CC_SYNTHESIZE(int, _hp, HP);
	CC_SYNTHESIZE(int, _defence, Defence);
	CC_SYNTHESIZE(int, _speed, Speed);
	CC_SYNTHESIZE(int, _level, Level);
};

#endif