#include "ceasar.h"
#include <cctype>

namespace core {

static char shift(char c, int k) {
  if (!std::isalpha(c))
    return c;
  char base = std::islower(c) ? 'a' : 'A';
  return (c - base + k + 26) % 26 + base;
}

std::string encrypt(const std::string &t, int k) {
  std::string r;
  for (char c : t)
    r += shift(c, k);
  return r;
}

std::string decrypt(const std::string &t, int k) { return encrypt(t, -k); }

} // namespace core
