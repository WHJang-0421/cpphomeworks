#include <no_strings_attached/string_trim.hpp>

namespace no_strings_attached {
std::string Trim(const std::string &str, char char_to_trim, Side side) {
  size_t left = 0UL, right = str.length();
  if (side == Side::kLeft || side == Side::kBoth) {
    while (left < str.length() && str.at(left) == char_to_trim) {
      ++left;
    }
  }
  if (side == Side::kRight || side == Side::kBoth) {
    while (right > left && str.at(right - 1) == char_to_trim) {
      --right;
    }
  }
  return str.substr(left, right - left);
}
std::string Trim(const std::string &str) { return Trim(str, ' ', Side::kBoth); }
} // namespace no_strings_attached
