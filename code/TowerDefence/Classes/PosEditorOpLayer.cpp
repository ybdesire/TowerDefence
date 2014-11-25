#include "PosEditorOpLayer.h"


PosEditorOpLayer::PosEditorOpLayer():
	_editorLayer(NULL)
{
}

PosEditorOpLayer::~PosEditorOpLayer()
{
	CC_SAFE_RELEASE(_editorLayer);
}



