#ifndef _POSEDITORLAYER_H_
#define _POSEDITORLAYER_H_

#include "cocos2d.h"
#include "PosBase.h"

using namespace cocos2d;


class PosEditorLayer: public Layer
{
public:
	PosEditorLayer();
	~PosEditorLayer();
	CREATE_FUNC(PosEditorLayer);
	virtual bool init();

private:
	void preLoad();//load level related background
	void editPos(Point pos);//create a pos or do nothing(choose the same area)
	void createPos(Point pos);//create position base
	PosBase *findExistPos(Point pos);
	void deletePosBase(PosBase *posbase);

	int _currentLevel;
	EnumPosType _posType;

	Vector<PosBase*> towerPoBaseList;
	Vector<PosBase*> monsterPoBaseList;
	
};

#endif

