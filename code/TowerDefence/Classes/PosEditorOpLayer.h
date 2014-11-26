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


	PosEditorLayer *_editorLayer;
};


#endif