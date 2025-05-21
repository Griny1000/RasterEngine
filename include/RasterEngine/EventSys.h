#pragma once
#include <memory>

namespace RE
{
    class EventSys 
    {
    public:
        virtual ~EventSys() = default;
        virtual bool ProcessEvents() = 0;
    };

    std::unique_ptr<EventSys> CreateEventSys();
}