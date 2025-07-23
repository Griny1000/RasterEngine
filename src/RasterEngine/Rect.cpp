#include "RasterEngine/Rect.h"

    RE::Rect::Rect(uint32_t  X, uint32_t Y, uint32_t width, uint32_t height, Color color)
        : m_PositionX(X), m_PositionY(Y), m_Width(width), m_Height(height), m_Color(color){}

    void RE::Rect::Draw(ColorBuffer& colorBuffer) const
    {
        const uint32_t bufferWidth = colorBuffer.GetWidth();
        const uint32_t bufferHeight = colorBuffer.GetHeight();
        const uint32_t endX = std::min(m_PositionX + m_Width, bufferWidth);
        const uint32_t endY = std::min(m_PositionY + m_Height, bufferHeight);

        Color* Buffer = colorBuffer.GetBuffer();
        
        for(int dy = m_PositionY; dy < endY; ++dy) 
        {
            int row = dy * bufferWidth;
            for(int dx = m_PositionX; dx < endX; ++dx)
            {
                Buffer[row + dx] = m_Color;
            }
            // Color* rowStart = Buffer + dy * bufferWidth + m_PositionX;
            // std::fill(rowStart, rowStart + (endX - m_PositionX), m_Color);
        }

    }