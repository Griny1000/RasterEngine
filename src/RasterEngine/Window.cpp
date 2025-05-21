#include "RasterEngine/Window.h"
#include <SDL.h>
#include <stdexcept>

namespace RE 
{
    namespace 
    {
        class SDLWindow : public Window 
        {
            SDL_Window* m_Window;
        public:
            SDLWindow(const std::string& title, uint32_t w, uint32_t h) 
            {
                m_Window = SDL_CreateWindow(
                    title.c_str(),
                    SDL_WINDOWPOS_CENTERED,
                    SDL_WINDOWPOS_CENTERED,
                    static_cast<int>(w),
                    static_cast<int>(h),
                    SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
                );
                if (!m_Window) throw std::runtime_error(SDL_GetError());
            }

            ~SDLWindow() override 
            {
                SDL_DestroyWindow(m_Window);
            }

            void SetTitle(const std::string& title) override 
            {
                SDL_SetWindowTitle(m_Window, title.c_str());
            }

            void Resize(uint32_t width, uint32_t height) override 
            {
                SDL_SetWindowSize(m_Window, 
                    static_cast<int>(width), 
                    static_cast<int>(height));
            }

            SDL_Window* GetSDLWindow() { return m_Window; }

            void* GetNativeHandle() const override 
            {
                return static_cast<void*>(m_Window);
            }
        };
    }

    std::unique_ptr<Window> CreateWindow(const std::string& title, 
                                       uint32_t width, 
                                       uint32_t height) 
                                       {
        return std::make_unique<SDLWindow>(title, width, height);
    }
}