#pragma once

#include "../event/event.h"

// forward declaration
namespace Constants
{
	struct Score;
}

class GameStateBase
{
public:
	GameStateBase(Constants::Score* score)
	{
		score_ = score;
	}
	virtual ~GameStateBase() = default;

	virtual void initialize() = 0;	// �X�e�[�g�̊J�n���ɂ��
	virtual void update() = 0;	// ���t���[��
	virtual void draw() = 0;	// ���t���[��
	virtual void exit() = 0;	// �X�e�[�g�̏I����

	// �X�e�[�g���I�������Ƃ��̃R�[���o�b�N
	Event<void, const std::shared_ptr<GameStateBase>&> onStateFinishedCallback;

protected:
	// ���L�f�[�^�A�N�Z�X�p
	Constants::Score* score_;
};