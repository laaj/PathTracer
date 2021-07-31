#include "utils.h"
#include "Log.h"

void pt::crash(const std::string& msg)
{
	Log::error("A crash occurred: {}", msg);
	std::exit(EXIT_FAILURE);
}
