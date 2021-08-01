#pragma once

#include <string>
#include <sstream>
#include <functional>

// An event system inspired by the one in The Cherno's game engine series.

namespace pt
{

enum class EventType
{
	None = 0,
	WindowClose, WindowResize,
	KeyPress, KeyRelease,
	MouseMove, MouseButtonPress, MouseButtonRelease, MouseScroll
};

#define EVENT_TYPE(type) virtual EventType getEventType() const override { return EventType::type; }\
						 static EventType getStaticType() { return EventType::type; }

class Event
{
public:
	virtual ~Event() = default;

	virtual std::string toString() const = 0;
	virtual EventType getEventType() const = 0;

	bool isHandled() const { return m_handled; }

	template <typename T>
	bool dispatch(std::function<bool(const T&)> fn)
	{
		if (getEventType() == T::getStaticType())
		{
			m_handled |= fn(static_cast<T&>(*this));
			return true;
		}
		return false;
	}

private:
	bool m_handled = false;
};

inline std::ostream& operator<<(std::ostream& os, const Event& event)
{
	os << event.toString();
	return os;
}

}