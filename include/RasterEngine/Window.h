#pragma once
#include <memory>
#include <string>

namespace RE 
{
    class Window {
    public:
        virtual ~Window() = default;
        virtual void SetTitle(const std::string& title) = 0;
        virtual void Resize(uint32_t width, uint32_t height) = 0;
        virtual void* GetNativeHandle() const = 0;
    };

    std::unique_ptr<Window> CreateWindow(const std::string& title, 
                                       uint32_t width, 
                                       uint32_t height);
}