#include "Core/Log.h"
#include "Application.h"
#include "Events/WindowEvent.h"

using namespace pt;

int main()
{
	{
		Log::init();

		Application app;
		app.run();
	}

	return 0;
}