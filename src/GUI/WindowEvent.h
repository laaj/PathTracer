#pragma once

#include "Event.h"

namespace pt
{

class WindowCloseEvent : public Event
{
public:
	WindowCloseEvent() = default;

	virtual std::string toString() const override { return "WindowClose"; }

	EVENT_TYPE(WindowClose)
};

class WindowResizeEvent : public Event
{
public:
	WindowResizeEvent(int width, int height) : m_width(width), m_height(height) {};

	uint32_t getWidth() const { return m_width; }
	uint32_t getHeight() const { return m_height; }

	virtual std::string toString() const override
	{
		std::stringstream ss;
		ss << "WindowResize: " << m_width << ", " << m_height;
		return ss.str();
	}

	EVENT_TYPE(WindowResize)

private:
	uint32_t m_width, m_height;
};

}