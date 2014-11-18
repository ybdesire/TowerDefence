#include "PosEditorScene.h"
#include "GetBackLayer.h"


PosEditorScene::PosEditorScene()
{
}

PosEditorScene::~PosEditorScene()
{
}


Scene *PosEditorScene::createScene()
{
	Scene *scene = Scene::create();

	//auto posEditorLay = PosEditorLayer::create();
	//scene->addChild(posEditorLay);

	auto getBackLayer = GetBackLayer::create();
	scene->addChild(getBackLayer);

	return scene;
}