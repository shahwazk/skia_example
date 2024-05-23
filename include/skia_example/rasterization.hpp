#ifndef SKIA_EXAMPLE_RASTERIZATION_HPP
#define SKIA_EXAMPLE_RASTERIZATION_HPP

#pragma once
#include <include/core/SkCanvas.h>
#include <include/core/SkStream.h>
#include <include/core/SkSurface.h>
#include <include/encode/SkPngEncoder.h>
namespace skia_example {

class Rasterization {

private:
    const std::string _path;
    void(*_draw)(SkCanvas*);
    const sk_sp<SkSurface> _rasterSurface;

public:
    Rasterization(const sk_sp<SkSurface>& rasterSurface, void(*draw)(SkCanvas*), const std::string& path);
    void Raster();
    void SavePNG();
};
} // namespace skia_example

#endif // SKIA_EXAMPLE_RASTERIZATION_HPP