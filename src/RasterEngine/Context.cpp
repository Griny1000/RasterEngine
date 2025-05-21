#include "RasterEngine/Context.h"
#include <SDL.h>
#include <stdexcept>

namespace RE
{
    GraphicsContext::GraphicsContext() 
    {
        if (SDL_Init(SDL_INIT_VIDEO) != 0)
            throw std::runtime_error(SDL_GetError());
    }

    GraphicsContext::~GraphicsContext() 
    {
        SDL_Quit();
    }
}