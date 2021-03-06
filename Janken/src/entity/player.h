#pragma once

#include "../constants/constants.h"

class Player
{
public:
	Player();
	~Player() = default;

	void setActive(bool);
	// leap motionから手を推定する
	void observeHand();

private:
	Constants::HandGesture hand_;
	bool is_active_;
	// TODO: LeapMotionの情報を取得するクラス
};