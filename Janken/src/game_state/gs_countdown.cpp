#include "gs_countdown.h"

#include "gs_play.h"

GS_Countdown::GS_Countdown() : GameStateBase(), count_(0), count_font_(80, Typeface::Bold)
{
	stopwatch_ = std::make_unique<Stopwatch>();
}

void GS_Countdown::initialize()
{
	stopwatch_->start();
}

void GS_Countdown::update()
{
	// �J�E���g�_�E��
	if (stopwatch_->ms() > 1000) {
		stopwatch_->reset();
		
		// �J�E���g�_�E���I��
		if (++count_ >= CountStr.size()) {
			// GS_Play�X�e�[�g�ֈڂ�
			invokeStateFinishedCallback(std::make_shared<GS_Play>());
			return;
		}
		
		stopwatch_->start();
	}
}

void GS_Countdown::draw()
{
	count_font_(CountStr[count_]).draw(Arg::center = Vec2(Window::Width() / 2, Window::Height() / 2));
}

void GS_Countdown::exit()
{
	
}