#pragma once

#include "Event.h"

namespace pt
{

class KeyEvent : public Event
{
public:
	int getKeyCode() const { return m_keyCode; }

protected:
	KeyEvent(int keyCode) : m_keyCode(keyCode) {}

	int m_keyCode;
};

class KeyPressEvent : public KeyEvent
{
public:
	KeyPressEvent(int keyCode, bool isRepeated) : KeyEvent(keyCode), m_isRepeated(isRepeated) {}

	bool isRepeated() const { return m_isRepeated; }

	virtual std::string toString() const override
	{
		std::stringstream ss;
		ss << "KeyPressEvent: " << m_keyCode << " (key), " << m_isRepeated << " (repeat)";
		return ss.str();
	}

	EVENT_TYPE(KeyPress)

private:
	bool m_isRepeated;
};

class KeyReleaseEvent : public KeyEvent
{
public:
	KeyReleaseEvent(int keyCode) : KeyEvent(keyCode) {}

	virtual std::string toString() const override
	{
		std::stringstream ss;
		ss << "KeyReleaseEvent: " << m_keyCode << " (key)";
		return ss.str();
	}

	EVENT_TYPE(KeyRelease)
};

}