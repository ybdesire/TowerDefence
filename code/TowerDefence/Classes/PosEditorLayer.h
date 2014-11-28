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

	void outPutToPositionListFile();
	void changePBType();//change position base type
	void editNextLevel();
	void editPreLevel();

private:
	void preLoad();//load level related background
	void editPos(Point pos);//create a pos or do nothing(choose the same area)
	void createPos(Point pos);//create position base
	PosBase *findExistPos(Point pos);//find exist position base at the 2 vector
	void deletePosBase(PosBase *posbase);//delete one position base from their list
	void deleteAllPB();//delete all position base from scene, and clear the lists

	int _currentLevel;
	EnumPosType _posType;

	Vector<PosBase*> towerPoBaseList;
	Vector<PosBase*> monsterPoBaseList;
	
};

#endif

