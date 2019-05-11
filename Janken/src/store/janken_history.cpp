#include "janken_history.h"

using QuestionPair = std::pair<Constants::HandGesture, bool>;

JankenHistory::JankenHistory() : questions_(std::vector<QuestionPair>()), correct_answers_(0)
{
	
}

void JankenHistory::push_back_question(const QuestionPair& question)
{
	questions_.push_back(question);

	onQuestionAddedCallback.invoke(question);
}

bool JankenHistory::addAnswer(const Constants::HandGesture hand)
{
	auto result = compare(hand, questions_.back().first);
	auto question = questions_.back().second;

	// 問題: 勝ってください			// 問題: 負けてください
	if ((question && result > 0) || (!question && result < 0)) {
		incrementCorrectAnswers();
		return true;
	}

	return false;
}

int JankenHistory::compare(const Constants::HandGesture hand1, const Constants::HandGesture hand2)
{
	// TODO
	// 強さがhand1 > hand2のとき return 1
	// hand1 == hand2 return 0
	// hand1 < hand2 return -1

	return 1;
}