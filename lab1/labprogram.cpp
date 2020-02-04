#include <iostream>

int main() {
  int Y; // Initialize variable Y in order to hold an integer value

  std::cout << "Enter an integer: ";
  std::cin >> Y;
  int X = (Y + 4) * 3;         // Initialize the integer X and define it to
  std::cout << X << std::endl; // contain the value of our integer Y + 4,
  return 0;                    // multiplied by 3x
}
