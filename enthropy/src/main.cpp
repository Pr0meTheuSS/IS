#include <iostream>
#include "entropy.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./entropy <file>\n";
        return 1;
    }

    std::string filename = argv[1];

    auto freq = calculateFrequencies(filename);
    double entropy = calculateEntropy(freq);

    std::cout << "Entropy: " << entropy << " bits per symbol\n";

    std::cout << "\nFrequencies:\n";
    for (int i = 0; i < 256; ++i) {
        if (freq[i] > 0) {
            std::cout << i << ": " << freq[i] << "\n";
        }
    }

    return 0;
}
