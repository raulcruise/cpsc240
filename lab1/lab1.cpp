#include <iostream>
#include "functions.h"

int main() {
  string input;
  string firstString;
  string secondString;
  int intInput;

  ///*
  std::cout << "1) Enter a 16 bit binary int: ";
  std::cin >> input;
  std::cout << intfrom16bit(input) << std::endl;

  std::cout << "2) Enter a 32 bit hexadecimal int: ";
  std::cin >> input;
  std::cout << intfrom32bithex(input) << std::endl;

  std::cout << "3) Enter an integer: ";
  std::cin >> intInput;
  std::cout << binaryfromint(intInput) << std::endl;

  std::cout << "4) Enter an integer: ";
  std::cin >> intInput;
  std::cout << hexadecimalfromint(intInput) << std::endl;

  std::cout << "5) Enter a string of digits: ";
  std::cin >> firstString;
  std::cout << "Enter a second string of digits: ";
  std::cin >> secondString;
  std::cout << "Enter a base: ";
  std::cin >> intInput;
  std::cout << "Sum: " << basenaddition(firstString, secondString, intInput) << std::endl;

  std::cout << "6) Enter a string of digits: ";
  std::cin >> firstString;
  std::cout << "Enter a second string of digits: ";
  std::cin >> secondString;
  std::cout << hexaddition(firstString, secondString) << std::endl;
  //*/
  std::cout << "7) Enter a single hexadecimal digit: ";
  std::cin >> firstString;
  std::cout << "Enter a hexadecimal string: ";
  std::cin >> secondString;
  std::cout << hexmultiplication(firstString, secondString) << std::endl;
}
