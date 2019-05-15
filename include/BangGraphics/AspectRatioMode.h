#pragma once

#include "BangMath/Vector2.h"

namespace Bang
{
enum class AspectRatioMode
{
    IGNORE,
    KEEP,
    KEEP_EXCEEDING
};

namespace AspectRatio
{
Vector2i GetAspectRatioedSize(const Vector2i &currentSize,
                              const Vector2i &targetSize,
                              AspectRatioMode aspectRatioMode);
}
}
