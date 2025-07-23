#pragma once
#include <memory>
#include <cstdint>


using Color = uint32_t;

namespace RE
{
    class ColorBuffer
    {
        private:
            std::unique_ptr<Color[]> m_ColorBuffer;
            int m_Width;
            int m_Height;

        public:
            ColorBuffer(uint32_t width, uint32_t hieght);

            void Clear(Color color);

            Color* GetBuffer() const;
            int GetWidth() const;
            int GetHeight() const;
    };
}