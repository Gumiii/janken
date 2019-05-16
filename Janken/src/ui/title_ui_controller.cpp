#include "title_ui_controller.h"
#include "../constants/constants.h"

TitleUIController::TitleUIController() : title_font_(80, Typeface::Bold), start_btn_(SimpleGUI::ButtonRegionAt(Constants::Title::StartBtnStr, Vec2(Window::Width() / 2, Window::Height() * 3 / 4), 150))
{
}

void TitleUIController::draw() const
{
	// �^�C�g��
	title_font_(Constants::Title::TitleStr).draw(Arg::topCenter = Vec2(Window::Width() / 2, Window::Height() / 4));

	// �X�^�[�g�{�^��
	// TODO: �{�^���N���X�쐬����
	SimpleGUI::ButtonAt(Constants::Title::StartBtnStr, Vec2(Window::Width() / 2, Window::Height() * 3 / 4), 150);
}

void TitleUIController::update()
{
	// �X�^�[�g�{�^�����N���b�N
	if (start_btn_.leftClicked()) {
		onStartBtnClickedCallback.invoke();
	}
}