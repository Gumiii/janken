#pragma once

#include <functional>

class GameStateBase
{
public:
	GameStateBase() = default;
	virtual ~GameStateBase() = default;

	virtual void initialize() = 0;	// �X�e�[�g�̊J�n���ɂ��
	virtual void update() = 0;	// ���t���[��
	virtual void draw() = 0;	// ���t���[��
	virtual void exit() = 0;	// �X�e�[�g�̏I����

	inline void setStateFinishedCallback(const std::function<void(const std::shared_ptr<GameStateBase>&)>& callback)
	{
		onStateFinishedCallback_ = callback;
	}

protected:
	inline void invokeStateFinishedCallback(const std::shared_ptr< GameStateBase>& state)
	{
				if (onStateFinishedCallback_) {
			onStateFinishedCallback_(state);
		}
	}

private:
	// �X�e�[�g���I�������Ƃ��̃R�[���o�b�N
	std::function<void(const std::shared_ptr<GameStateBase>&)> onStateFinishedCallback_;
};