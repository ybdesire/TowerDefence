#ifndef _GETBACKLAYER_H_
#define _GETBACKLAYER_H_

#include "cocos2d.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;

class GetBackLayer: public Layer
{
public:
	GetBackLayer();
	~GetBackLayer();
	CREATE_FUNC(GetBackLayer);
	virtual bool init(); 

private:
	void getBack(Ref *pSender, Control::EventType event);
};

#endif

