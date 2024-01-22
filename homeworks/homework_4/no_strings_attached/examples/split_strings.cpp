#include <no_strings_attached/string_split.h>
#include <iostream>

using std::string_literals::operator""s;

int main() {
  std::cout << "Example program that splits strings.\nPlease enter a string:";
  std::string str_to_split;
  std::getline(std::cin, str_to_split);
  std::cout << "\nYour split string:";

  for (const std::string &elem :
       no_strings_attached::Split(str_to_split, " "s)) {
    std::cout << " '" << elem << "'";
  }
  std::cout << std::endl;
}
