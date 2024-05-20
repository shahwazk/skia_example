/*
This code is an example of how to use skia API.
*/

#include "include/core/SkCanvas.h"
#include "include/core/SkData.h"
#include "include/core/SkImage.h"
#include "include/core/SkStream.h"
#include "include/core/SkSurface.h"
#include "include/encode/SkPngEncoder.h"
#include "include/core/SkPath.h"


void draw(SkCanvas* canvas) {
    const SkScalar scale = 256.0f;
    const SkScalar R = 0.45f * scale;
    const SkScalar TAU = 6.2831853f;
    SkPath path;
    path.moveTo(R, 0.0f);
    for (int i = 1; i < 7; ++i) {
        SkScalar theta = 3 * i * TAU / 7;
        path.lineTo(R * cos(theta), R * sin(theta));
    }
    path.close();
    SkPaint p;
    p.setAntiAlias(true);
    canvas->clear(SK_ColorWHITE);
    canvas->translate(0.5f * scale, 0.5f * scale);
    canvas->drawPath(path, p);
}

void raster(int width, int height, void (*draw)(SkCanvas*), const char* path) {
  sk_sp<SkSurface> rasterSurface(SkSurfaces::Raster(SkImageInfo::MakeN32Premul(width, height)));
  if (!rasterSurface) {
      return;
  }
  SkCanvas* rasterCanvas = rasterSurface->getCanvas();
  draw(rasterCanvas);
  sk_sp<SkImage> img = rasterSurface->makeImageSnapshot();
  if (!img) {
      return;
  }
  SkPngEncoder::Options options;
  options.fZLibLevel = 9; // Compression level
  sk_sp<SkData> png = SkPngEncoder::Encode(nullptr, img.get(), options);
  if (!png) {
      return;
  }
  SkFILEWStream out(path);
  (void)out.write(png->data(), png->size());
}



int main() {
  raster(300, 300, draw, "output.png");
  return 0;
}
