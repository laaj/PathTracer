#pragma once

#include "Events/Event.h"

namespace pt
{

class Editor
{
public:
	Editor() = default;
	~Editor();

	void init();

	void render();

private:
	bool handleEvent(Event& event);
};

}