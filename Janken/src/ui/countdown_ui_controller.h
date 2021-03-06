#pragma once

#include <Siv3D/Font.hpp>

class CountdownUIController
{
public:
	CountdownUIController();
	~CountdownUIController() = default;

	void draw(int) const;
	void update();

private:
	const s3d::Font count_font_;
	
	// intからchar32_tへ変換
	char32_t int2chr32(int) const;
};