#ifndef _POSEDITOROPLAYER_H_
#define _POSEDITOROPLAYER_H_

#include "cocos2d.h"
#include "cocos-ext.h"
#include "PosEditorLayer.h"

using namespace cocos2d;
USING_NS_CC_EXT;

class PosEditorOpLayer: public Layer
{
public:
	PosEditorOpLayer();
	~PosEditorOpLayer();

	static PosEditorOpLayer *create(PosEditorLayer *layer);

private:
	PosEditorLayer *_editorLayer;
};


#endif