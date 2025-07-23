#include "RasterEngine/Grid.h"

    RE::Grid::Grid(uint32_t  size, Color color)
        : m_Size(size), m_Color(color) {}

    void RE::Grid::Draw(ColorBuffer& colorBuffer) const
    {
        int Width = colorBuffer.GetWidth();
        int Height = colorBuffer.GetHeight();
        Color* Buffer = colorBuffer.GetBuffer();
        
        for(int dy = 0; dy < Height; dy += m_Size) 
        {
            int row = dy * Width;
            for(int dx = 0; dx < Width; dx += m_Size)
            {
                Buffer[row + dx] = m_Color;
            }
        }
    }