#pragma once

#include "Window.h"

namespace pt
{

class ImGuiContext
{
public:
	ImGuiContext() = default;
	~ImGuiContext();

	void init();

	void startRender();
	void endRender();

	void blockKeyboard(bool block) { m_blockKeyboard = block; }
	void blockMouse(bool block) { m_blockMouse = block; }

private:
	bool m_blockKeyboard = true;
	bool m_blockMouse = true;
};

}