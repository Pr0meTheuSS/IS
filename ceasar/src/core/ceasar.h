#pragma once
#include <string>

namespace core {
std::string encrypt(const std::string &text, int key);
std::string decrypt(const std::string &text, int key);
} // namespace core
