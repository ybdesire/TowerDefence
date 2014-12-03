#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_

#include "cocos2d.h"

using namespace cocos2d;

class GameScene: public Layer
{
public:
	static Scene *create(int level);
};


#endif