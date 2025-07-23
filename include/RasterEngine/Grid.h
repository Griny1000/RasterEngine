#pragma onca
#include "RasterEngine/Primitive.h"
#include "RasterEngine/ColorBuffer.h"

namespace RE
{
class Grid : public Primitive 
{
private:
    uint32_t m_Size;
    Color m_Color;

public:
    Grid(uint32_t  size, Color color);
    void Draw(ColorBuffer& colorBuffer) const override ;
    
};
}