#include <iostream>
#include <ostream>
#include <random>

int main() {
  int min_num, max_num;

  std::cout << "Welcome to the GUESSING GAME!\nI will generate a number and "
               "you will guess it!"
            << std::endl;
  std::cout << "Please provide the smallest number:" << std::endl;
  std::cin >> min_num;
  std::cout << "Please provide the largest number:" << std::endl;
  std::cin >> max_num;

  // generate random number
  std::random_device rd;
  std::default_random_engine rand_engine{rd()};
  std::uniform_int_distribution distribution{min_num, max_num};
  int answer = distribution(rand_engine);

  int user_try, k = 0;
  std::cout << "I've generated a number. Try to guess it!" << std::endl;
  while (true) {
    std::cout << "Please provide the next guess: ";
    std::cin >> user_try;
    ++k;

    if (user_try < answer) {
      std::cout << "Your number is too small. Try again!" << std::endl;
    } else if (user_try > answer) {
      std::cout << "Your number is too big. Try again!" << std::endl;
    } else {
      std::cout << "You've done it! You guessed the number " << answer << " in "
                << k << " guesses!";
      break;
    }
  }
}
