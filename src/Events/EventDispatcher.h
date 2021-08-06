#pragma once

#include <vector>
#include <functional>
#include <typeinfo>
#include <typeindex>
#include "Event.h"
#include "WindowEvent.h"

namespace pt
{

class EventDispatcher
{
public:
	class Binder
	{
	public:
		Binder(EventDispatcher* dispatcher)
			: m_dispatcher(dispatcher) {}

		template <typename EventType,
				  typename F,
				  typename = std::enable_if_t<std::is_base_of<Event, EventType>::value>>
		void addHandler(const F& handler)
		{
			m_dispatcher->m_handlers.emplace_back(typeid(EventType), [=](Event& ev) {
				return handler(static_cast<EventType&>(ev));
			});
		}

	private:
		EventDispatcher* m_dispatcher;
	};

	friend class Binder;

public:
	EventDispatcher()
		: m_binder(this) {}

	void dispatch(Event& ev)
	{
		Log::trace(ev);
		std::type_index eventType(typeid(ev));
		for (auto handler = m_handlers.rbegin(); handler != m_handlers.rend(); handler++)
		{
			if (handler->type == eventType)
			{
				if (handler->callback(ev))
					break;
			}
		}
	}

	Binder& getBinder() { return m_binder; }

private:
	struct EventHandler
	{
		std::type_index type;
		std::function<bool(Event&)> callback;

		EventHandler(const std::type_info& type, const std::function<bool(Event&)>& callback)
			: type(type), callback(callback) {}
	};
	std::vector<EventHandler> m_handlers;
	Binder m_binder;
};

}