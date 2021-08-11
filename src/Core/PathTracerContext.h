#pragma once

#include "UI/Window.h"

namespace pt
{

class PathTracerContext
{
public:
	PathTracerContext() = default;

	void renderImGui();

private:
	bool m_viewportFocused = false;
	bool m_viewportHovered = false;
};

}