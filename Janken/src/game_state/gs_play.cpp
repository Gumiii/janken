#include "gs_play.h"

#include "../store/janken_history.h"
#include "../scene/result.h"

using question_pair = std::pair<Constants::HandGesture, bool>;

GS_Play::GS_Play() : GameStateBase(), ui_controller_(), history_(), generator_(), player_(), stopwatch_()
{
}

void GS_Play::initialize()
{
	Print << U"play state";

	// ��肪�������ꂽ�Ƃ��̃R�[���o�b�N��o�^
	history_.onQuestionAddedCallback.set([&](const question_pair& questions) {
		this->player_.setActive(true);
		this->stopwatch_.start();
		this->ui_controller_.update(questions);
	});

	player_.setActive(false);

	newQuestion();
}

void GS_Play::update()
{
	// ���Ԑ؂�
	if (stopwatch_.isRunning() && stopwatch_.ms() > Constants::Play::MaxWaitMs) {
		stopwatch_.reset();
		player_.setActive(false);

		// ���̖���
		next();
		return;
	}

	// TODO: LeapMotion�������擾
	// HandGesture hand = getHand()
	// auto correct = history_.addAnswer(hand);
	// if (correct) next();
}

void GS_Play::draw()
{
	ui_controller_.draw();
}

void GS_Play::exit()
{

}

void GS_Play::next()
{
	if (history_.getTotalNumberOfQuestions() >= Constants::Play::MaxNumOfQuestions) {
		// �X�e�[�g�I��
		onStateFinishedCallback.invoke(nullptr);
		return;
	}

	newQuestion();
}

void GS_Play::newQuestion()
{	
	auto hand = generator_.randomHand();
	auto is_winning = generator_.isWinningOrLosing();
	auto question = question_pair(hand, is_winning);
	
	history_.push_back_question(question);

	Print << U"add question";
}