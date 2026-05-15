#include "dictionary.h"
#include <algorithm>
#include <fstream>

namespace utils {

std::vector<std::string> load_dict(const std::string &path) {
  std::vector<std::string> d;
  std::ifstream f(path);

  std::string w;
  while (f >> w) {
    std::transform(w.begin(), w.end(), w.begin(), ::tolower);
    d.push_back(w);
  }
  return d;
}

} // namespace utils