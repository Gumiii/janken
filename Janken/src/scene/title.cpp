#include "title.h"

#include <memory>

#include <Siv3D.hpp>

TitleScene::TitleScene(const InitData& data) : SceneBase(data), title_font_(80, Typeface::Bold), start_btn_(SimpleGUI::ButtonRegionAt(Constants::Title::StartBtnStr, Vec2(Window::Width() / 2, Window::Height() * 3 / 4), 150))
{
	initialize();
}

void TitleScene::update()
{
	// �X�^�[�g�{�^�����N���b�N
	if (start_btn_.leftClicked()) {
		onSceneChanged(Constants::Scene::Play);
	}
}

void TitleScene::draw() const
{
	// �^�C�g��
	title_font_(Constants::Title::TitleStr).draw(Arg::topCenter = Vec2(Window::Width() / 2, Window::Height() / 4));

	// �X�^�[�g�{�^��
	// TODO: �{�^���N���X�쐬����
	//SimpleGUI::ButtonAt(Constants::Title::StartBtnStr, Vec2(Window::Width() / 2, Window::Height() * 3 / 4), 150);
	start_btn_.draw();
}

void TitleScene::initialize()
{
	ClearPrint();
	Print << U"initialize title";
}

void TitleScene::exit()
{
	Print << U"exit title";
}