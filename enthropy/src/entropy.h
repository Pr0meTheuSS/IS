#pragma once
#include <string>
#include <vector>

std::vector<size_t> calculateFrequencies(const std::string& filename);
double calculateEntropy(const std::vector<size_t>& freq);

