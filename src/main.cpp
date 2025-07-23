#include "RasterEngine/Context.h"
#include "RasterEngine/Window.h"
#include "RasterEngine/Renderer.h"
#include "RasterEngine/EventSys.h"
#include "RasterEngine/IDrawable.h"
#include "RasterEngine/ITransformable.h"
#include "RasterEngine/Grid.h"
#include "RasterEngine/Rect.h"
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

        RE::Grid grid(10, 0xFF333333);
        RE::Rect rect(300, 200, 300, 150, 0xFFFF00FF);
        renderer->Push(&grid);
        renderer->Push(&rect);
        

        bool running = true;
        while (running) {
            running = eventSys->ProcessEvents();
            
            renderer->SetClearColor(0, 0, 0, 255);
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