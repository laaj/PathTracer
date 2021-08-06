#pragma once

#include <string>
#include <spdlog/fmt/ostr.h>

namespace pt
{

class Event
{
public:
	virtual ~Event() = default;

	virtual std::string toString() const = 0;

    template<typename OStream>
    friend OStream& operator<<(OStream& os, const Event& ev)
    {
        return os << ev.toString();
    }
};

}