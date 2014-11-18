#ifndef _POSEDITORLAYER_H_
#define _POSEDITORLAYER_H_

#include "cocos2d.h"

using namespace cocos2d;

class PosEditorLayer: public Layer
{
public:
	PosEditorLayer();
	~PosEditorLayer();
	CREATE_FUNC(PosEditorLayer);
	virtual bool init();

};

#endif

