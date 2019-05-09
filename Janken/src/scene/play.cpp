#include "play.h"

#include "../game_state/gs_countdown.h"
#include "../constants/constants.h"

PlayScene::PlayScene(const InitData& data) : IScene(data)
{
	initialize();
}

void PlayScene::update()
{
	current_state_->update();
}

void PlayScene::draw() const
{
	current_state_->draw();
}

void PlayScene::initialize()
{
	ClearPrint();
	Print << U"initialize play";

	changeState(std::make_shared<GS_Countdown>());
}

void PlayScene::exit()
{
	Print << U"exit play";

	current_state_->exit();
}

void PlayScene::changeState(const std::shared_ptr<GameStateBase>& state)
{
	if (current_state_) {
		current_state_->exit();
		current_state_->setStateFinishedCallback(nullptr);
	}

	// ���̃X�e�[�g��nullptr�ł���΃��U���g��
	if (state == nullptr) {
		exit();
		changeScene(Constants::Scene::Result);
		return;
	}

	current_state_ = state;

	// �C�x���g�̓o�^
	current_state_->setStateFinishedCallback(
		[&](std::shared_ptr<GameStateBase> state) {
		this->changeState(state); }
	);
	
	current_state_->initialize();
}