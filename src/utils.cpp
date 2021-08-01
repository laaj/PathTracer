#include "utils.h"
#include "Log.h"

void pt::crash(const std::string& msg)
{
	Log::error("Critical error: {}", msg);
	std::exit(EXIT_FAILURE);
}
