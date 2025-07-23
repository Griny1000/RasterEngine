#pragma once
#include "ColorBuffer.h"

namespace RE
{
    class IDrawable
    {
        public:

        virtual void Draw(RE::ColorBuffer& colorBuffer) const = 0;
        virtual ~IDrawable()  = default;
    };
}