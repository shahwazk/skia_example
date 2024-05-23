#include "skia_example/rasterization.hpp"

namespace skia_example {

Rasterization::Rasterization(const sk_sp<SkSurface>& rasterSurface, void(*draw)(SkCanvas*), const std::string &path)
    : _path(path + std::string("output.png"))
    , _draw(draw)
    , _rasterSurface(rasterSurface)
    {}

void Rasterization::Raster() {
    
    if (!_rasterSurface) {
        return;
        }
    SkCanvas *rasterCanvas = _rasterSurface->getCanvas();
    _draw(rasterCanvas);
}

void Rasterization::SavePNG()
{
    sk_sp<SkImage> _rasterImageToPNG = _rasterSurface->makeImageSnapshot();
    if (!_rasterImageToPNG) {
        return;
        }
    SkPngEncoder::Options options;
    options.fZLibLevel = 9; // Compression level
    sk_sp<SkData> png = SkPngEncoder::Encode(nullptr, _rasterImageToPNG.get(), options);
    if (!png) {
        return;
        }
    SkFILEWStream out(_path.c_str());
    (void)out.write(png->data(), png->size());
}
} // namespace skia_example