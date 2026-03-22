#include <iostream>
#include "struct.h"
#include "function.h"

int main(){
    const std::string inputFileName = "input.bmp";
    std::ifstream file(inputFileName, std::ios::binary);

    if (!file) {
        std::cerr << "can't find file" << inputFileName << std::endl;
        return 1;
    }

    // --- read bmp headers ---
    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;
    file.read((char*)&fileHeader, sizeof(fileHeader));
    file.read((char*)&infoHeader, sizeof(infoHeader));

    if (fileHeader.bfType != 0x4D42) {
        std::cerr << "not bmp file" << std::endl;
        return 1;
    }

    int width = infoHeader.biWidth;
    int height = std::abs(infoHeader.biHeight);
    int rowStride = (width * 3 + 3) & ~3;

    // --- read pixel data ---
    std::vector<uint8_t> pixelData(rowStride * height);
    file.seekg(fileHeader.bfOffBits, std::ios::beg);
    file.read((char*)pixelData.data(), pixelData.size());
    file.close();

    std::vector<YUV> yuvData(width * height);
    double minY = 255.0, maxY = 0.0;

    // --- RGB -> YUV ---
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int idx = y * rowStride + x * 3;
            YUV val = rgbToYuv(pixelData[idx+2], pixelData[idx+1], pixelData[idx]);
            yuvData[y * width + x] = val;
            minY = std::min(minY, val.y);
            maxY = std::max(maxY, val.y);
        }
    }

    // --- Rearrange gray intensity to lie between [0,255] ---
    std::vector<uint8_t> grayPixels(rowStride * height, 0);
    for (int i = 0; i < width * height; ++i) {
        if (maxY != minY) 
            yuvData[i].y = (yuvData[i].y - minY) / (maxY - minY) * 255.0;
        
        int y_pos = i / width;
        int x_pos = i % width;
        int idx = y_pos * rowStride + x_pos * 3;
        uint8_t g = (uint8_t)yuvData[i].y;
        grayPixels[idx] = grayPixels[idx+1] = grayPixels[idx+2] = g;
    }

    // --- Write a grayscale bmp ---
    std::ofstream grayFile("gray.bmp", std::ios::binary);
    grayFile.write((char*)&fileHeader, sizeof(fileHeader));
    grayFile.write((char*)&infoHeader, sizeof(infoHeader));
    grayFile.write((char*)grayPixels.data(), grayPixels.size());
    grayFile.close();

    // --- Change the luminance value Y and YUV->RGB---
    std::vector<uint8_t> outputColorPixels(rowStride * height);
    for (int i = 0; i < width * height; ++i) {
        yuvData[i].y = std::clamp(yuvData[i].y * 1.25, 0.0, 255.0); 
        
        uint8_t r, g, b;
        yuvToRgb(yuvData[i], r, g, b);
        
        int y_pos = i / width;
        int x_pos = i % width;
        int idx = y_pos * rowStride + x_pos * 3;
        outputColorPixels[idx] = b; 
        outputColorPixels[idx+1] = g;
        outputColorPixels[idx+2] = r;
    }

    // --- Write a color bmp ---
    std::ofstream colorFile("output_color.bmp", std::ios::binary);
    colorFile.write((char*)&fileHeader, sizeof(fileHeader));
    colorFile.write((char*)&infoHeader, sizeof(infoHeader));
    colorFile.write((char*)outputColorPixels.data(), outputColorPixels.size());
    colorFile.close();

    std::cout << "1. Gray image generated: gray.bmp" << std::endl;
    std::cout << "2. Color image generated: output_color.bmp" << std::endl;

    return 0; 
}