#include "gs_countdown.h"

#include <Siv3D.hpp>

#include "gs_play.h"
#include "../constants/constants.h"

GS_Countdown::GS_Countdown() : GameStateBase(),  stopwatch_(), count_(Constants::Play::MaxCountdown)
{
}

void GS_Countdown::initialize()
{
	stopwatch_.start();
}

void GS_Countdown::update()
{
	// �J�E���g�_�E��
	if (stopwatch_.ms() > 1000) {
		stopwatch_.reset();
		
		// �J�E���g�_�E���I��
		if (--count_ <= 0) {
			// GS_Play�X�e�[�g�ֈڂ�
			invokeStateFinishedCallback(std::make_shared<GS_Play>());
			return;
		}
		
		stopwatch_.start();
	}
}

void GS_Countdown::draw()
{
	// �J�E���g�_�E���\��
	ui_controller.drawCountdown(count_);
}

void GS_Countdown::exit()
{
	
}