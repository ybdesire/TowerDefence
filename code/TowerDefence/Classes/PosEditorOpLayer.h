#ifndef _POSEDITOROPLAYER_H_
#define _POSEDITOROPLAYER_H_

#include "cocos2d.h"
#include "cocos-ext.h"
#include "PosEditorLayer.h"

using namespace cocos2d;
using namespace cocos2d::extension;

class PosEditorOpLayer: public Layer
{
public:
	PosEditorOpLayer();
	~PosEditorOpLayer();

	static PosEditorOpLayer *create(PosEditorLayer *layer);
	virtual bool init(PosEditorLayer *layer);

private:
	void addControls();

	//Out put positions to file
	void addOutPutCtr(Size visibleSize);
	void outputPosToPlistFile(Ref* pSender, Control::EventType event);

	//Change position base type at EnumPosType
	void addPBTypeChgCtr(Size visibleSize);
	void changePosBaseType(Ref *pSender, Control::EventType event);

	void addNextLvlCtr(Size visibleSize);
	void changeToNextLvl(Ref *pSender, Control::EventType event);

	void addPreviousLvlCtr(Size visibleSize);
	void changeToPreLvl(Ref *pSender, Control::EventType event);


	PosEditorLayer *_editorLayer;
};


#endif