#include "PosBase.h"


#define Tower_Radius 32
#define Monster_Radius 10


PosBase::PosBase()
{
	_pos = CCPointMake(0,0);
	_isDebug = false;
	_posType = enTowerPos;
}

PosBase::~PosBase()
{
}

PosBase *PosBase::create(Point pos, EnumPosType posType, bool isDebug)
{
	PosBase *pbs = new PosBase();

	if(pbs && pbs->init(pos, posType, isDebug))
	{
		pbs->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(pbs);
	}

	return pbs;
}

bool PosBase::init(Point pos, EnumPosType posType, bool isDebug)
{
	setPos(pos);
	_posType = posType;
	_isDebug = isDebug;
	return true;
}

void PosBase::draw(Renderer *renderer, const Mat4& transform, uint32_t flags)
{
	if(_isDebug)
	{
		glLineWidth(5);

		float radius;

		if(_posType == enTowerPos)
		{
			radius = Tower_Radius;
		}
		else
		{
			radius = Monster_Radius;
		}

		if(_posType == enTowerPos)
		{
			Point srcPos = Point(_pos.x-radius, _pos.y+radius);
			Point destPos = Point(_pos.x+radius, _pos.y-radius);

			ccDrawRect(srcPos,destPos);
		}
		else
		{ //draw MonsterPos
			ccDrawCircle(_pos, radius, 360, 20, false);
		}

		glLineWidth(1);
	}
}

bool PosBase::isClickMe(Point pos)
{
	float radius;

	if(_posType == enTowerPos)
	{
		radius = Tower_Radius;
	}
	else
	{
		radius = Monster_Radius;
	}

	Point srcPoint = Point(_pos.x-radius, _pos.y-radius);
	Point dstPoint = Point(_pos.x+radius, _pos.y+radius);

	if( (pos.x >= srcPoint.x && pos.x<=dstPoint.x) && (pos.y>=srcPoint.y && pos.y<=dstPoint.y) )
	{
		return true;
	}

	else
		return false;
		

}



