#pragma once
#include <memory>
#include <cstdint>

namespace RE 
{
    class Window;

    class Renderer
    {
    public:
        virtual ~Renderer() = default;
        virtual void Clear() = 0;
        virtual void Present() = 0;
        virtual void SetClearColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) = 0;
    };

    std::unique_ptr<Renderer> CreateRenderer(Window& window);
}