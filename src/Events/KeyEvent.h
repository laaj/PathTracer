#pragma once

#include "Event.h"
#include <sstream>

namespace pt
{

class KeyEvent : public Event
{
public:
	int getKeyCode() const { return m_keyCode; }

protected:
	KeyEvent(int keyCode)
		: m_keyCode(keyCode) {}

	int m_keyCode;
};

class KeyPressEvent : public KeyEvent
{
public:
	KeyPressEvent(int keyCode, bool repeated)
		: KeyEvent(keyCode), m_repeated(repeated) {}

	bool isRepeated() const { return m_repeated; }

	virtual std::string toString() const override
	{
		std::stringstream ss;
		ss << "KeyPressEvent: " << m_keyCode << " (" << (m_repeated  ? "repeated" : "single") << ")";
		return ss.str();
	}

private:
	bool m_repeated;
};

class KeyReleaseEvent : public KeyEvent
{
public:
	KeyReleaseEvent(int keyCode)
		: KeyEvent(keyCode) {}

	virtual std::string toString() const override
	{
		std::stringstream ss;
		ss << "KeyReleaseEvent: " << m_keyCode;
		return ss.str();
	}
};

}