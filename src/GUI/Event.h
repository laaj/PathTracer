#pragma once

#include <string>
#include <sstream>

namespace pt
{

enum class EventType
{
	None = 0,
	WindowClose, WindowResize,
	KeyPress, KeyRelease,
	MouseMove, MouseButtonPress, MouseButtonRelease, MouseScroll
};

#define EVENT_TYPE(type) virtual EventType getType() const override { return EventType::type; }\
						 static EventType getStaticType() { return EventType::type; }

class Event
{
public:
	virtual ~Event() = default;

	virtual std::string toString() const = 0;
	virtual EventType getType() const = 0;

	bool isHandled() { return m_handled; }

	template <typename T>
	bool dispatch(bool (*callbackFn)(const Event&))
	{
		if (getType() == T::getStaticType())
		{
			m_handled |= callbackFn(static_cast<const Event&>(*this));
			return true;
		}
		return false;
	}

private:
	bool m_handled = false;
};

}