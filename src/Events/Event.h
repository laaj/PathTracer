#pragma once

#include <string>
#include <spdlog/fmt/ostr.h>

namespace pt
{

enum class EventCategory
{
    None = 0,
    Application = 1 << 0,
    Keyboard    = 1 << 1,
    Mouse       = 1 << 2
};

inline EventCategory operator&(EventCategory a, EventCategory b)
{
    return static_cast<EventCategory>(static_cast<int>(a) & static_cast<int>(b));
}

inline EventCategory operator|(EventCategory a, EventCategory b)
{
    return static_cast<EventCategory>(static_cast<int>(a) | static_cast<int>(b));
}

class Event
{
public:
	virtual ~Event() = default;

	virtual std::string toString() const = 0;
    virtual EventCategory getEventCategory() const = 0;

    bool isInCategory(EventCategory flags) const { return static_cast<bool>(flags & getEventCategory()); }

    template<typename OStream>
    friend OStream& operator<<(OStream& os, const Event& ev)
    {
        return os << ev.toString();
    }
};

}