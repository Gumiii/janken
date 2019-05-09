#pragma once

#include "../constants/constants.h"

class Player
{
public:
	Player();
	~Player() = default;

	void setActive(bool);
	// leap motion�����𐄒肷��
	void observeHand();

private:
	Constants::HandGesture hand_;
	bool is_active_;
	// HandRecognizer recognizer_;
};