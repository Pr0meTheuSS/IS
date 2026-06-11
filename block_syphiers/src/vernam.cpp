#include "vernam.h"
#include <fstream>

void vernamXOR(const std::string& input,
               const std::string& key,
               const std::string& output) {

    std::ifstream in(input, std::ios::binary);
    std::ifstream k(key, std::ios::binary);
    std::ofstream out(output, std::ios::binary);

    char c1, c2;

    while (in.get(c1) && k.get(c2)) {
        char res = c1 ^ c2;
        out.put(res);
    }
}
