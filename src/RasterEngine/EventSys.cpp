#include "RasterEngine/EventSys.h"
#include <SDL.h>

namespace RE
{
    namespace 
    {
        class SDLEventSys : public EventSys 
        {
        public:
            bool ProcessEvents() override 
            {
                SDL_Event event;
                while (SDL_PollEvent(&event)) 
                {
                    if (event.type == SDL_QUIT) return false;
                    else if(event.key.keysym.sym == SDLK_ESCAPE)
                        return false;
                }
                return true;
            }
        };
    }

    std::unique_ptr<EventSys> CreateEventSys() 
    {
        return std::make_unique<SDLEventSys>();
    }
}