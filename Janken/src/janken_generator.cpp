#include "janken_generator.h"

Constants::HandGesture JankenGenerator::randomHand()
{
	// ��������_���Ɍ���
	//�����𐶐�
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> rand100(1, 99);

	//�����̌��ʂɂ��C������߂�
	if (rand100(mt) % 3 == 0)
		return Constants::HandGesture::Goo;
	else if (rand100(mt) % 3 == 1)
		return Constants::HandGesture::Choki;
	else
		return Constants::HandGesture::Pa;
}

bool JankenGenerator::isWinningOrLosing()
{
	// �����_���ŏ��������邩�����߂�
	//�����𐶐�
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> rand100(0, 99);

	//�����̌��ʂɂ��C�������������߂�
	if (rand100(mt) % 2 == 0) return true;
	else  return false;
}