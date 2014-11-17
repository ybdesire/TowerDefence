#ifndef _GETBACKLAYER_H_
#define _GETBACKLAYER_H_

#include "cocos2d.h"


using namespace cocos2d;

class GetBackLayer: public Layer
{
public:
	GetBackLayer();
	~GetBackLayer();
	CREATE_FUNC(GetBackLayer);
	virtual bool init(); 
};

#endif

