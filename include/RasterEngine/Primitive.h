#pragma once

#include "RasterEngine/IDrawable.h"
#include "RasterEngine/ITransformable.h"

namespace RE
{
   class Primitive : public IDrawable {
   public:
        virtual ~Primitive() = default;
}; 
}