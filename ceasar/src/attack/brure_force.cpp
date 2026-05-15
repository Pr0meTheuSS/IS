#include "../core/ceasar.h"
#include "attack.h"

namespace attack {

std::vector<std::pair<int, std::string>> brute(const std::string &c) {
  std::vector<std::pair<int, std::string>> r;
  for (int k = 0; k < 26; ++k) {
    r.emplace_back(k, core::decrypt(c, k));
  }
  return r;
}

} // namespace attack
