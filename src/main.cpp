#include "Core/Log.h"

int main()
{
	pt::Log::init();
	pt::Log::info("Hello, {}!", "World");
	pt::Log::trace("Hello, {}!", "World");
	pt::Log::warn("Hello, {}!", "World");
	pt::Log::error("Hello, {}!", "World");

	return 0;
}