#include "function.h"

YUV rgbToYuv(uint8_t r, uint8_t g, uint8_t b) {
    YUV res;
    res.y =  0.299 * r + 0.587 * g + 0.114 * b;
    res.u = -0.147 * r - 0.289 * g + 0.436 * b;
    res.v =  0.615 * r - 0.515 * g - 0.100 * b;
    return res;
}

void yuvToRgb(YUV yuv, uint8_t &r, uint8_t &g, uint8_t &b) {
    int rt = std::round(yuv.y + 1.140 * yuv.v);
    int gt = std::round(yuv.y - 0.395 * yuv.u - 0.581 * yuv.v);
    int bt = std::round(yuv.y + 2.032 * yuv.u);
    r = (uint8_t)std::clamp(rt, 0, 255);
    g = (uint8_t)std::clamp(gt, 0, 255);
    b = (uint8_t)std::clamp(bt, 0, 255);
}

