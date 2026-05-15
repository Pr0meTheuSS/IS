#include "../core/ceasar.h"
#include "attack.h"
#include <algorithm>
#include <sstream>
#include <unordered_set>
#include <vector>

#include <fmt/core.h>

namespace attack {

static std::vector<std::string> split_words(const std::string &s) {
  std::vector<std::string> words;
  std::string w;
  std::istringstream iss(s);

  while (iss >> w) {
    words.push_back(w);
  }

  return words;
}

struct Candidate {
  int key;
  std::string text;
  double score;
};

static double calc_score(const std::string &t,
                         const std::unordered_set<std::string> &dict) {
  std::string s = t;
  std::transform(s.begin(), s.end(), s.begin(), ::tolower);

  auto words = split_words(s);

  if (words.empty())
    return 0.0;

  int matches = 0;

  for (auto &w : words) {
    if (dict.count(w)) {
      matches++;
    }
  }

  return static_cast<double>(matches) / static_cast<double>(words.size());
}

std::vector<std::pair<int, std::string>>
dictionary(const std::string &c, const std::vector<std::string> &d) {

  std::unordered_set<std::string> dict(d.begin(), d.end());
  std::vector<Candidate> candidates;

  for (int k = 0; k < 26; ++k) {
    auto t = core::decrypt(c, k);
    double score = calc_score(t, dict);

    candidates.push_back({k, t, score});
  }

  std::sort(
      candidates.begin(), candidates.end(),
      [](const Candidate &a, const Candidate &b) { return a.score > b.score; });

  std::vector<std::pair<int, std::string>> result;

  // TOP-3
  int limit = std::min(3, (int)candidates.size());

  for (int i = 0; i < limit; ++i) {
    fmt::print("{}: {} (score {:.2f})\n", candidates[i].key, candidates[i].text,
               candidates[i].score);

    result.emplace_back(candidates[i].key, candidates[i].text);
  }

  // если есть 100% совпадение — можно явно отметить
  if (!candidates.empty() && candidates[0].score == 1.0) {
    fmt::print("\n[+] EXACT MATCH FOUND (100% dictionary match)\n");
  }

  return result;
}

} // namespace attack
