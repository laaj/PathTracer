#include "Log.h"

using namespace pt;

int main()
{
	Log::init();

	Log::info("Hello, {}!", "World");
	Log::trace("Hello, {}!", "World");
	Log::warn("Hello, {}!", "World");
	Log::error("Hello, {}!", "World");

	return 0;
}