#include <iostream>
#include "vernam.h"
#include "rc4.h"
#include "rng.h"

int main() {
    std::cout << "Generating key...\n";
    generateLCGFile("key.bin", 100000, 12345);

    std::cout << "Vernam encrypt...\n";
    vernamXOR("input.txt", "key.bin", "encrypted.bin");

    std::cout << "Vernam decrypt...\n";
    vernamXOR("encrypted.bin", "key.bin", "decrypted.txt");

    std::cout << "RC4 encrypt...\n";
    std::vector<unsigned char> key = {'k','e','y'};
    rc4Process("input.txt", "rc4_enc.bin", key);

    std::cout << "RC4 decrypt...\n";
    rc4Process("rc4_enc.bin", "rc4_dec.txt", key);

    std::cout << "Done\n";
    return 0;
}
