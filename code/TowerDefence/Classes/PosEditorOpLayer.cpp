#include "PosEditorOpLayer.h"


PosEditorOpLayer::PosEditorOpLayer():
	_editorLayer(NULL)
{
}

PosEditorOpLayer::~PosEditorOpLayer()
{
	CC_SAFE_RELEASE(_editorLayer);
}

PosEditorOpLayer *PosEditorOpLayer::create(PosEditorLayer *layer)
{
	auto oplayer = new PosEditorOpLayer();
	
	if(oplayer && oplayer->init(layer))
	{
		oplayer->autorelease();
	}
	else
	{
		CC_SAFE_RELEASE(oplayer);
	}

	return oplayer;
}

bool PosEditorOpLayer::init(PosEditorLayer *layer)
{
	if (!Layer::init())
	{
		return false;
	}
	CC_SAFE_RETAIN(layer);

	addControls();

	return true;
}

void PosEditorOpLayer::addControls()
{

}


