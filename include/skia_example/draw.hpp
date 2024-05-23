#ifndef SKIA_EXAMPLE_DRAW_HPP
#define SKIA_EXAMPLE_DRAW_HPP

#pragma once
#include "include/core/SkCanvas.h"

namespace skia_example {

class DrawUtils {

public:
    virtual void Draw(SkCanvas* canvas) = 0;
};
}  // namespace skia_example

#endif  // SKIA_EXAMPLE_DRAW_HPP