#include "RasterEngine/ColorBuffer.h"
#include <SDL.h>

using Color = uint32_t;

namespace RE
{
    ColorBuffer::ColorBuffer(uint32_t width, uint32_t height) : m_Width(width), m_Height(height), m_ColorBuffer(std::make_unique<Color[]>(width * height)) {}

    void ColorBuffer::Clear(Color color)
    {
        const int totalPixels = m_Width * m_Height;
        for(int i = 0; i < totalPixels; ++i) 
        {
            m_ColorBuffer[i] = color;
        }
    }

    Color* ColorBuffer::GetBuffer() const
    {
        return m_ColorBuffer.get();
    }

    int ColorBuffer::GetWidth() const
    {
        return m_Width;
    }

    int ColorBuffer::GetHeight() const
    {
        return m_Height;
    }
}