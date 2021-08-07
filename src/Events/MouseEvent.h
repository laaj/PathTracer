#pragma once

#include "Event.h"
#include <sstream>

namespace pt
{

class MouseButtonEvent : public Event
{
public:
	virtual EventCategory getEventCategory() const override
	{
		return EventCategory::Mouse;
	}

	int getButton() const { return m_button; }

protected:
	MouseButtonEvent(int button)
		: m_button(button) {}

	int m_button;
};

class MouseButtonPressEvent : public MouseButtonEvent
{
public:
	MouseButtonPressEvent(int button)
		: MouseButtonEvent(button) {}

	virtual std::string toString() const override
	{
		std::stringstream ss;
		ss << "MouseButtonPressEvent: " << m_button;
		return ss.str();
	}
};

class MouseButtonReleaseEvent : public MouseButtonEvent
{
public:
	MouseButtonReleaseEvent(int button)
		: MouseButtonEvent(button) {}

	virtual std::string toString() const override
	{
		std::stringstream ss;
		ss << "MouseButtonReleaseEvent: " << m_button;
		return ss.str();
	}
};

class MouseMoveEvent : public Event
{
public:
	MouseMoveEvent(float x, float y)
		: m_x(x), m_y(y) {}

	float getX() const { return m_x; }
	float getY() const { return m_y; }

	virtual std::string toString() const override
	{
		std::stringstream ss;
		ss << "MouseMoveEvent: " << m_x << ", " << m_y;
		return ss.str();
	}

	virtual EventCategory getEventCategory() const override
	{
		return EventCategory::Mouse;
	}

private:
	float m_x, m_y;
};

class MouseScrollEvent : public Event
{
public:
	MouseScrollEvent(float xOffset, float yOffset)
		: m_xOffset(xOffset), m_yOffset(yOffset) {}

	float getXOffset() const { return m_xOffset; }
	float getYOffset() const { return m_yOffset; }

	virtual std::string toString() const override
	{
		std::stringstream ss;
		ss << "MouseScrollEvent: " << m_xOffset << ", " << m_yOffset;
		return ss.str();
	}

	virtual EventCategory getEventCategory() const override
	{
		return EventCategory::Mouse;
	}

private:
	float m_xOffset, m_yOffset;
};

}