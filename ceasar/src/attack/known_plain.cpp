#include "attack.h"
#include "../core/ceasar.h"

namespace attack {

int known_plain(const std::string& p, const std::string& c) {
    for (int k = 0; k < 26; ++k) {
        if (core::encrypt(p, k) == c) return k;
    }
    return -1;
}

}
