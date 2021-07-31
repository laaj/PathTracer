#pragma once

#include "Event.h"

namespace pt
{

class MouseButtonEvent : public Event
{
public:
	int getButton() const { return m_button; }

protected:
	MouseButtonEvent(int button) : m_button(button) {}

	int m_button;
};

class MousePressEvent : public MouseButtonEvent
{
public:
	MousePressEvent(int button) : MouseButtonEvent(button) {}

	virtual std::string toString() const override
	{
		std::stringstream ss;
		ss << "MousePressEvent: " << m_button << " (button)";
		return ss.str();
	}

	EVENT_TYPE(MouseButtonPress)
};

class MouseReleaseEvent : public MouseButtonEvent
{
public:
	MouseReleaseEvent(int button) : MouseButtonEvent(button) {}

	virtual std::string toString() const override
	{
		std::stringstream ss;
		ss << "MouseReleaseEvent: " << m_button << " (button)";
		return ss.str();
	}

	EVENT_TYPE(MouseButtonRelease)
};

class MouseMoveEvent : public Event
{
public:
	MouseMoveEvent(float x, float y) : m_x(x), m_y(y) {}

	float getX() const { return m_x; }
	float getY() const { return m_y; }

	virtual std::string toString() const override
	{
		std::stringstream ss;
		ss << "MouseMoveEvent: " << m_x << ", " << m_y;
		return ss.str();
	}

	EVENT_TYPE(MouseMove)

private:
	float m_x, m_y;
};

class MouseScrollEvent : public Event
{
public:
	MouseScrollEvent(float xOffset, float yOffset) : m_xOffset(xOffset), m_yOffset(yOffset) {}

	virtual std::string toString() const override
	{
		std::stringstream ss;
		ss << "MouseScrollEvent: " << m_xOffset << ", " << m_yOffset;
		return ss.str();
	}

	EVENT_TYPE(MouseScroll)

private:
	float m_xOffset, m_yOffset;
};

}