#include "app.h"
#include "attack/attack.h"
#include "core/ceasar.h"
#include "utils/dictionary.h"
#include <cxxopts.hpp>
#include <fmt/core.h>
#include <fstream>
#include <sstream>

std::string read_file(const std::string &path) {
  std::ifstream file(path);
  if (!file) {
    throw std::runtime_error("Cannot open file: " + path);
  }

  std::stringstream buffer;
  buffer << file.rdbuf();
  return buffer.str();
}

bool write_file(const std::string &path, const std::string &content) {
  std::ofstream file(path);
  if (!file) {
    return false;
  }
  file << content;
  return true;
}

int run_cli(int argc, char **argv) {
  cxxopts::Options opts("caesar", "Caesar cipher CLI tool");

  opts.add_options()("m,mode", "Mode: enc | dec | brute | dict",
                     cxxopts::value<std::string>())(
      "t,text", "Input text", cxxopts::value<std::string>()->default_value(""))(
      "f,file", "Path to txt file",
      cxxopts::value<std::string>()->default_value(""))(
      "o,out", "Output file path",
      cxxopts::value<std::string>()->default_value(""))(
      "k,key", "Shift key (for enc/dec)",
      cxxopts::value<int>()->default_value("0"))(
      "d,dict", "Dictionary file (for dict mode)",
      cxxopts::value<std::string>()->default_value(""))("h,help", "Show help");

  try {
    auto res = opts.parse(argc, argv);

    if (res.count("help") || argc == 1) {
      fmt::print("{}\n", opts.help());
      return 0;
    }

    if (!res.count("mode")) {
      fmt::print("Error: --mode is required\n\n{}\n", opts.help());
      return 1;
    }

    auto mode = res["mode"].as<std::string>();
    auto text = res["text"].as<std::string>();
    auto file_path = res["file"].as<std::string>();
    auto out_path = res["out"].as<std::string>();
    int key = res["key"].as<int>();

    if (!file_path.empty()) {
      try {
        text = read_file(file_path);
      } catch (const std::exception &e) {
        fmt::print("Error: {}\n", e.what());
        return 1;
      }
    }

    if (text.empty()) {
      fmt::print("Error: no input text (--text or --file)\n\n{}\n",
                 opts.help());
      return 1;
    }

    std::stringstream output;

    if (mode == "enc") {
      output << core::encrypt(text, key) << "\n";
    } else if (mode == "dec") {
      output << core::decrypt(text, key) << "\n";
    } else if (mode == "brute") {
      for (auto &[k, t] : attack::brute(text))
        output << k << ": " << t << "\n";
    } else if (mode == "dict") {
      auto dict_file = res["dict"].as<std::string>();
      if (dict_file.empty()) {
        fmt::print("Error: --dict is required for dict mode\n\n{}\n",
                   opts.help());
        return 1;
      }

      auto d = utils::load_dict(dict_file);
      for (auto &[k, t] : attack::dictionary(text, d))
        output << k << ": " << t << "\n";
    } else {
      fmt::print("Error: unknown mode '{}'\n\n{}\n", mode, opts.help());
      return 1;
    }

    auto result = output.str();

    fmt::print("{}", result);

    if (!out_path.empty()) {
      if (!write_file(out_path, result)) {
        fmt::print("Error: cannot write to file {}\n", out_path);
        return 1;
      }
    }

    return 0;

  } catch (const cxxopts::exceptions::exception &e) {
    fmt::print("Argument error: {}\n\n{}\n", e.what(), opts.help());
    return 1;
  }
}