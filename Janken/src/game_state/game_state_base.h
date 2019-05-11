#pragma once

#include "../event/event.h"

class GameStateBase
{
public:
	GameStateBase() = default;
	virtual ~GameStateBase() = default;

	virtual void initialize() = 0;	// �X�e�[�g�̊J�n���ɂ��
	virtual void update() = 0;	// ���t���[��
	virtual void draw() = 0;	// ���t���[��
	virtual void exit() = 0;	// �X�e�[�g�̏I����

	// �X�e�[�g���I�������Ƃ��̃R�[���o�b�N
	Event<void, const std::shared_ptr<GameStateBase>&> onStateFinishedCallback;
};