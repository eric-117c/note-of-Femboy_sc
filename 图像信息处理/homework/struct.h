#ifndef _STRUCT_H_
#define _STRUCT_H_
#include <cstdint>
#pragma pack(push, 1)
struct BMPFileHeader {
    uint16_t bfType{0x4D42}; // 'BM'
    uint32_t bfSize{0};
    uint16_t bfReserved1{0};
    uint16_t bfReserved2{0};
    uint32_t bfOffBits{0};
};

struct BMPInfoHeader {
    uint32_t biSize{40};
    int32_t  biWidth{0};
    int32_t  biHeight{0};
    uint16_t biPlanes{1};
    uint16_t biBitCount{24}; // 24位真彩色
    uint32_t biCompression{0};
    uint32_t biSizeImage{0};
    int32_t  biXPelsPerMeter{0};
    int32_t  biYPelsPerMeter{0};
    uint32_t biClrUsed{0};
    uint32_t biClrImportant{0};
};
#pragma pack(pop)

struct YUV {
    double y, u, v;
};
#endif