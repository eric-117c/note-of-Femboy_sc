#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>
#include "struct.h"
YUV rgbToYuv(uint8_t r, uint8_t g, uint8_t b);
void yuvToRgb(YUV yuv, uint8_t &r, uint8_t &g, uint8_t &b);
#endif