#include <array>
#include <iostream>
#include <map>
#include <ostream>
#include <string>
#include <vector>

int main() {
  std::string name, time_of_year, adj_1, adj_2;

  std::cout << "Welcome to the fortune teller program!" << std::endl;
  std::cout << "Please enter your name:" << std::endl;
  std::cin >> name;
  std::cout << "Please enter the time of year when you were born:\n(pick from "
               "'spring', 'summer', 'autumn', 'winter')"
            << std::endl;
  std::cin >> time_of_year;
  std::cout << "Please enter an adjective:" << std::endl;
  std::cin >> adj_1;
  std::cout << "Please enter another adjective:" << std::endl;
  std::cin >> adj_2;

  std::vector adj = {adj_1, adj_2};
  std::map<std::string, std::string> time_to_noun = {
      {"spring", "STL guru"},
      {"summer", "C++ expert"},
      {"autumn", "coding beast"},
      {"winter", "software design hero"},
  };
  std::array ending = {"eats UB for breakfast",
                       "finds errors quicker than the compiler",
                       "is not afraid of C++ error messages"};

  std::cout << "\nHere is your description:" << std::endl;
  std::cout << name << ", the " << adj[name.length() % adj.size()] << " "
            << time_to_noun[time_of_year] << " that "
            << ending[name.length() % ending.size()] << std::endl;
}
