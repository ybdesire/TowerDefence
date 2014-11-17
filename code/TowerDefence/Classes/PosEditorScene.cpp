#include "PosEditorScene.h"


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

	return scene;
}