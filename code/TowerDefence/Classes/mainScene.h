#ifndef _MAINSCENE_H_
#define _MAINSCENE_H_

#include "cocos2d.h"

using namespace cocos2d;

class mainScene: public Layer
{
public:
	mainScene();
	~mainScene();
	static Scene *createScene();

private:
	virtual bool init();//override declines the function at current class will override the same function at their base class; so if the function is not declined as base class, compile error
	CREATE_FUNC(mainScene);

	void createChooseMenu();//choose menu creation
	// call back function for choose menu button
	void editorScene(Ref *pSender);
	void startGame(Ref *pSender);
};

#endif
