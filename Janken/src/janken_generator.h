#pragma once

#include "constants/constants.h"

class JankenGenerator
{
public:
	JankenGenerator() = default;
	~JankenGenerator() = default;

	// �����_���Ɏ�����肷��
	Constants::HandGesture randomHand();
	// ��蕶�u����(true)�vor�u������(false)�v
	bool isWinningOrLosing();
};