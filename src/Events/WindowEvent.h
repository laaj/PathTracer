#pragma once

#include "Event.h"
#include <sstream>

namespace pt
{

class WindowCloseEvent : public Event
{
public:
	WindowCloseEvent() = default;

	virtual std::string toString() const override
	{
		return "WindowCloseEvent";
	}

	virtual EventCategory getEventCategory() const override
	{
		return EventCategory::Application;
	}
};

class WindowResizeEvent : public Event
{
public:
	WindowResizeEvent(uint32_t width, uint32_t height)
		: m_width(width), m_height(height) {}

	uint32_t getWidth() const { return m_width; }
	uint32_t getHeight() const { return m_height; }

	virtual std::string toString() const override
	{
		std::stringstream ss;
		ss << "WindowResizeEvent: " << m_width << " " << m_height;
		return ss.str();
	}

	virtual EventCategory getEventCategory() const override
	{
		return EventCategory::Application;
	}

private:
	uint32_t m_width, m_height;
};

}