#pragma once

#include <string>

namespace pt
{

#ifdef _MSC_VER
#	define PT_DEBUGBREAK() __debugbreak()
#	define PT_ASSUMEZERO() __assume(0)
#else
#	define PT_DEBUGBREAK() 
#	define PT_ASSUMEZERO()
#endif

#ifdef PT_DEBUG
#	define PT_ASSERT(cond) if (!(cond)) PT_DEBUGBREAK()
#	define PT_UNREACHABLE() PT_DEBUGBREAK()
#else
#	define PT_ASSERT(cond)
#	define PT_UNREACHABLE() PT_ASSUMEZERO()
#endif

#define PT_UNUSED(x) (void)(x)

#define PT_BIND_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

void crash(const std::string& msg);

}