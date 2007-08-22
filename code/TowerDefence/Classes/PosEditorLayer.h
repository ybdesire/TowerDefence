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
	void preLoad();
	void editPos(Point pos);

	int _currentLevel;
	EnumPosType _posType;
	
};

#endif

