#pragma once
#include <string>
#include <vector>

namespace attack {
    int known_plain(const std::string&, const std::string&);
    std::vector<std::pair<int, std::string>> brute(const std::string&);
    std::vector<std::pair<int, std::string>> dictionary(
        const std::string&,
        const std::vector<std::string>&
    );
}
