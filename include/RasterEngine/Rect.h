#pragma once
#include "RasterEngine/Primitive.h"
#include "RasterEngine/ColorBuffer.h"

namespace RE
{
    class Rect : public Primitive
    {
        private:
        uint32_t m_PositionX;
        uint32_t m_PositionY;

        uint32_t m_Width;
        uint32_t m_Height;

        Color    m_Color;

    public:
        Rect(uint32_t  X, uint32_t y, uint32_t width, uint32_t height, Color color);
        void Draw(ColorBuffer& colorBuffer) const override ;
    };
}