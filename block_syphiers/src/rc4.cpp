#include "rc4.h"
#include <fstream>

RC4::RC4(const std::vector<unsigned char>& key) : S(256) {
    for (int i = 0; i < 256; ++i)
        S[i] = i;

    int j = 0;
    for (int i = 0; i < 256; ++i) {
        j = (j + S[i] + key[i % key.size()]) % 256;
        std::swap(S[i], S[j]);
    }
}

unsigned char RC4::getByte() {
    i = (i + 1) % 256;
    j = (j + S[i]) % 256;
    std::swap(S[i], S[j]);
    return S[(S[i] + S[j]) % 256];
}

void rc4Process(const std::string& input,
                const std::string& output,
                const std::vector<unsigned char>& key) {

    std::ifstream in(input, std::ios::binary);
    std::ofstream out(output, std::ios::binary);

    RC4 rc4(key);

    char c;
    while (in.get(c)) {
        unsigned char k = rc4.getByte();
        out.put(c ^ k);
    }
}
