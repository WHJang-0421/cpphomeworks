#include "../no_strings_attached/string_trim.h"
#include <iostream>

using std::string_literals::operator""s;

int main() {
  std::cout << "Example program that trims strings.\nPlease enter a string:";
  std::string str_to_trim;
  std::getline(std::cin, str_to_trim);
  std::cout << "\nYour trimmed string: '"
            << no_strings_attached::Trim(str_to_trim) << "'" << std::endl;
}
