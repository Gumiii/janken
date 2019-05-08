#pragma once

#include <functional>

#include"constants/constants.h"

class JankenHistory
{
public:
	JankenHistory();
	~JankenHistory() = default;

	// �W�����P���̋�����r
	int compare(const Constants::HandGesture&, const Constants::HandGesture&);

	inline void setQuestionAddedCallback(const std::function<void(std::pair<Constants::HandGesture, bool>)>&);

private:
	inline void invokeQuestionAddedCallback(const std::pair<Constants::HandGesture, bool>&);

	// ��肪�ǉ����ꂽ�Ƃ��̃R�[���o�b�N
	std::function<void(std::pair<Constants::HandGesture, bool>)> onQuestionAddedCallback_;
	std::vector<std::pair<Constants::HandGesture, bool>> questions_;
	int correct_answers_;
};