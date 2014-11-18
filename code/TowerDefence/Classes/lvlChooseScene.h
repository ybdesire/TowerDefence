#ifndef _LVLCHOOSESCENE_H_
#define _LVLCHOOSESCENE_H_

#include "cocos2d.h"

using namespace cocos2d;

class lvlChooseScene: public Layer
{
public:
	lvlChooseScene();
	~lvlChooseScene();
	static Scene *createScene();

private:
	CREATE_FUNC(lvlChooseScene);
	virtual bool init();

	Label* createLvlLabel(const char *lvlstr);
	void lvl1(Ref *pSender);
	void lvl2(Ref *pSender);
	void lvl3(Ref *pSender);


	int _lvl;
};


#endif