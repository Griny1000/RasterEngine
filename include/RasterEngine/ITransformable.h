#pragma once


namespace RE
{
        class ITransformable 
        {
        public:
            virtual void Translate(float x, float y, float z) = 0;
            virtual void Scale(float factor) = 0;
            virtual void Rotation(float angle) = 0;
            virtual ~ITransformable() = default;
        };
}