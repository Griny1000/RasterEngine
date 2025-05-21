#include "RasterEngine/Context.h"
#include "RasterEngine/Window.h"
#include "RasterEngine/Renderer.h"
#include "RasterEngine/EventSys.h"
#include <iostream>
#include <memory>
#include <SDL.h>

int main(int argc, char* argv[]) 
{
    try 
    {
        RE::GraphicsContext context;
        auto window = RE::CreateWindow("Hello Raster Engine", 800, 600);
        auto renderer = RE::CreateRenderer(*window);
        auto eventSys = RE::CreateEventSys();

        bool running = true;
        while (running) {
            running = eventSys->ProcessEvents();
            
            renderer->SetClearColor(0, 255, 0, 255);
            renderer->Clear();
            renderer->Present();
        }
    } catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}