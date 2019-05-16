#include "play_ui_controller.h"

PlayUIController::PlayUIController(): question_font_(50, Typeface::Bold)
{

}

void PlayUIController::draw() const
{
	// $BLdBj$rI=<((B
	String question = question_flg_ ? Question_Str[0] : Question_Str[1];
	question_font_(question).drawAt(Window::Width() / 2, Window::Height() / 6);

	// $B<j$rIA2h(B
	int index = static_cast<int>(hand_);
	Hand_Texture[index].scaled(2.0).drawAt(Window::Width() / 2, Window::Height() / 2);
}

void PlayUIController::update(const std::pair<Constants::HandGesture, bool>& question)
{
	// $BLdBj$N99?7(B
	hand_ = question.first;
	question_flg_ = question.second;
}