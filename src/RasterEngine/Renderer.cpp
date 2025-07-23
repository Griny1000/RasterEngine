#include "RasterEngine/Renderer.h"
#include "RasterEngine/Window.h"
#include "RasterEngine/ColorBuffer.h"
#include "RasterEngine/IDrawable.h"
#include "RasterEngine/Primitive.h"

#include <SDL.h>
#include <stdexcept>
#include <vector>


namespace RE 
{
    namespace 
    {

        class SDLRenderer : public Renderer 
        {
            SDL_Renderer*            m_Renderer;
            SDL_Texture*             m_ColorBufferTexture;
            RE::ColorBuffer          m_ColorBuffer;
            std::vector<IDrawable*>   m_Drawers;

            void SwapColorBuffer()
            {
                SDL_UpdateTexture
                (
                    m_ColorBufferTexture,
                    NULL,
                    m_ColorBuffer.GetBuffer(),
                    static_cast<int>(m_ColorBuffer.GetWidth() * sizeof(uint32_t))
                );
                SDL_RenderCopy(m_Renderer, m_ColorBufferTexture, NULL, NULL);
            }
        public:
            explicit SDLRenderer(RE::Window* windowHandle) : m_ColorBuffer(windowHandle->GetWidth(), windowHandle->GetHeight())
            {
                SDL_Window* sdlWindow = static_cast<SDL_Window*>(windowHandle->GetNativeHandle());
                m_Renderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);
                if (!m_Renderer) throw std::runtime_error(SDL_GetError());

                m_ColorBufferTexture = SDL_CreateTexture
                (
                    m_Renderer,
                    SDL_PIXELFORMAT_ARGB8888,
                    SDL_TEXTUREACCESS_STREAMING,
                    windowHandle->GetWidth(),
                    windowHandle->GetHeight()  
                );
            }

            ~SDLRenderer() override 
            {
                SDL_DestroyRenderer(m_Renderer);
            }

            void Clear() override { SDL_RenderClear(m_Renderer); }
            void Present() override 
            {     
                for(auto i = 0; i < m_Drawers.size(); ++i)
                {
                    m_Drawers[i]->Draw(m_ColorBuffer);
                }

                SwapColorBuffer();

                m_ColorBuffer.Clear(0x00000000);
                SDL_RenderPresent(m_Renderer);               
            }
            void SetClearColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) override 
            {
                SDL_SetRenderDrawColor(m_Renderer, r, g, b, a);
            }

            void Push(IDrawable* drawable)
            {
                m_Drawers.push_back(drawable);
            }
        };
    }

    std::unique_ptr<Renderer> CreateRenderer(Window& window) 
    {
        return std::make_unique<SDLRenderer>(&window);
    }
}