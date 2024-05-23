#ifndef SKIA_EXAMPLE_SHAPES_HPP
#define SKIA_EXAMPLE_SHAPES_HPP

#pragma once
#include "include/core/SkCanvas.h"
#include "skia_example/draw.hpp"

namespace skia_example {

class Shapes : public DrawUtils {
public:
    void Draw(SkCanvas* canvas) override;
};
}  // namespace skia_example

#endif  // SKIA_EXAMPLE_SHAPES_HPP