#include "PosEditorScene.h"
#include "GetBackLayer.h"
#include "PosEditorLayer.h"
#include "PosEditorOpLayer.h"


PosEditorScene::PosEditorScene()
{
}

PosEditorScene::~PosEditorScene()
{
}


Scene *PosEditorScene::createScene()
{
	Scene *scene = Scene::create();

	auto posEditorLayer = PosEditorLayer::create();
	scene->addChild(posEditorLayer);

	auto posEditorOpLayer = PosEditorOpLayer::create(posEditorLayer);
	scene->addChild(posEditorOpLayer);

	auto getBackLayer = GetBackLayer::create();
	scene->addChild(getBackLayer);

	return scene;
}