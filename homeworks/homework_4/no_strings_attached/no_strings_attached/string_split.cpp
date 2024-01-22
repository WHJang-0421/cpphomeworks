#include <no_strings_attached/string_split.hpp>

namespace no_strings_attached {
std::vector<std::string> Split(const std::string &str,
                               const std::string &delimiter,
                               int number_of_chunks_to_keep) {
  std::vector<std::string> result;
  auto start = 0UL, end = 0UL;
  do {
    if (result.size() == static_cast<size_t>(number_of_chunks_to_keep)) {
      break;
    }

    end = str.find(delimiter, start);
    result.emplace_back(str.substr(start, end - start));
    start = end + delimiter.length();
  } while (end != std::string::npos);
  return result;
}

std::vector<std::string> Split(const std::string &str,
                               const std::string &delimiter) {
  return Split(str, delimiter, str.length());
}
} // namespace no_strings_attached
