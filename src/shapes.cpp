#include "skia_example/shapes.hpp"
#include "include/core/SkPaint.h"
#include "include/core/SkRRect.h"
#include "include/core/SkRect.h"

namespace skia_example {

void Shapes::Draw(SkCanvas* canvas){
    canvas->drawColor(SK_ColorWHITE);

    SkPaint paint;
    paint.setStyle(SkPaint::kFill_Style);
    paint.setAntiAlias(true);
    paint.setStrokeWidth(4);
    paint.setColor(0xff4285F4);

    SkRect rect = SkRect::MakeXYWH(10, 10, 100, 160);
    canvas->drawRect(rect, paint);

    SkRRect oval;
    oval.setOval(rect);
    oval.offset(40, 80);
    paint.setColor(0xffDB4437);
    canvas->drawRRect(oval, paint);

    paint.setColor(0xff0F9D58);
    canvas->drawCircle(180, 50, 25, paint);

    rect.offset(80, 50);
    paint.setColor(0xffF4B400);
    paint.setStyle(SkPaint::kStroke_Style);
    canvas->drawRoundRect(rect, 10, 10, paint);
}
}  // namespace skia_example