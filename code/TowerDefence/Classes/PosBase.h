#ifndef _POSBASE_H_
#define _POSBASE_H_

#include "cocos2d.h"

using namespace cocos2d;

enum  EnumPosType
{
	enTowerPos,
	enMonsterPos
};

class PosBase: public Node
{
public:
	PosBase();
	~PosBase();
	virtual bool init(Point pos, EnumPosType posType, bool isDebug);
	static PosBase *create(Point pos, EnumPosType posType, bool isDebug);
	virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);

protected:
	CC_SYNTHESIZE(Point,_pos,Pos);
	bool _isDebug;
	EnumPosType _posType;
};



#endif