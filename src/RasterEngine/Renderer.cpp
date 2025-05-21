#include "RasterEngine/Renderer.h"
#include "RasterEngine/Window.h"
#include <SDL.h>
#include <stdexcept>

namespace RE 
{
    namespace 
    {

        class SDLRenderer : public Renderer 
        {
            SDL_Renderer* m_Renderer;
        public:
            explicit SDLRenderer(void* windowHandle) 
            {
                SDL_Window* sdlWindow = static_cast<SDL_Window*>(windowHandle);
                m_Renderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);
                if (!m_Renderer) throw std::runtime_error(SDL_GetError());
            }

            ~SDLRenderer() override 
            {
                SDL_DestroyRenderer(m_Renderer);
            }

            void Clear() override { SDL_RenderClear(m_Renderer); }
            void Present() override { SDL_RenderPresent(m_Renderer); }
            void SetClearColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) override 
            {
                SDL_SetRenderDrawColor(m_Renderer, r, g, b, a);
            }
        };
    }

    std::unique_ptr<Renderer> CreateRenderer(Window& window) 
    {
        return std::make_unique<SDLRenderer>(window.GetNativeHandle());
    }
}