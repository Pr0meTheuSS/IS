#include "entropy.h"
#include <fstream>
#include <cmath>

std::vector<size_t> calculateFrequencies(const std::string& filename) {
    std::vector<size_t> freq(256, 0);

    std::ifstream file(filename, std::ios::binary);
    char c;

    while (file.get(c)) {
        unsigned char uc = static_cast<unsigned char>(c);
        freq[uc]++;
    }

    return freq;
}

double calculateEntropy(const std::vector<size_t>& freq) {
    size_t total = 0;
    for (auto f : freq) total += f;

    if (total == 0) return 0.0;

    double entropy = 0.0;

    for (auto f : freq) {
        if (f == 0) continue;

        double p = static_cast<double>(f) / total;
        entropy -= p * std::log2(p);
    }

    return entropy;
}

