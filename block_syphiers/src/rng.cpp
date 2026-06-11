#include "rng.h"
#include <fstream>

void generateLCGFile(const std::string& filename, size_t size, uint32_t seed) {
    std::ofstream out(filename, std::ios::binary);

    uint32_t a = 1664525;
    uint32_t c = 1013904223;
    uint32_t m = 0xFFFFFFFF;

    uint32_t x = seed;

    for (size_t i = 0; i < size; ++i) {
        x = (a * x + c) % m;
        unsigned char byte = x & 0xFF;
        out.write((char*)&byte, 1);
    }
}
