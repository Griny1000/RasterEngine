#pragma once

namespace RE 
{
    class GraphicsContext 
    {
    public:
        GraphicsContext();
        ~GraphicsContext();
        
        GraphicsContext(const GraphicsContext&) = delete;
        GraphicsContext& operator=(const GraphicsContext&) = delete;
    };
}