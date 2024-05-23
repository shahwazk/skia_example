/*
This code is an example of how to use skia API.
*/
#include <iostream>
#include "include/core/SkSurface.h"
#include "skia_example/rasterization.hpp"
#include "skia_example/shapes.hpp"
#include "include/core/SkCanvas.h"

using namespace skia_example;

int main() {

    // SkSurface to be passed for all the canvas
    int width = 300;
    int height = 300;
    sk_sp<SkSurface> rasterSurface(SkSurfaces::Raster(SkImageInfo::MakeN32Premul(width, height)));

    auto drawFunc = [](SkCanvas* canvas) {
        Shapes().Draw(canvas);
    };
    std::string path = "/home/bot/rds_ws/src/skia_example/generated_images/";
    Rasterization raster(rasterSurface, drawFunc, path.c_str());
    raster.Raster();
    raster.SavePNG();
    return 0;
}
