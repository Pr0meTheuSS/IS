#pragma once
#include <vector>
#include <string>

class RC4 {
public:
    RC4(const std::vector<unsigned char>& key);
    unsigned char getByte();

private:
    std::vector<unsigned char> S;
    int i = 0, j = 0;
};

void rc4Process(const std::string& input,
                const std::string& output,
                const std::vector<unsigned char>& key);
