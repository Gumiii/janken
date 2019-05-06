#pragma once

#include <HamFramework/SceneManager.hpp>

#include "../constants/constants.h"

// TODO:��������
class SceneBase : public SceneManager<Constants::Scene>::Scene
{
public:
	SceneBase(const InitData& data) : IScene(data)
	{
	}

	virtual void initialize() = 0;	// REVIEW: �����Ă�������
	virtual void exit() = 0;

protected:
	// �V�[���ύX���ɌĂ�
	// exit()�Y��h�~�̂��߁CIScene::changeScene()�͎g�p���Ȃ�
	void onSceneChanged(Constants::Scene scene)
	{
		exit();
		changeScene(scene);
	}
};