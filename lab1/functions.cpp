#include "functions.h"

int hexchartoint(char character) {
  // If a numeric character is recieved, return it's integer value.
  // If an alphabetic character is recieved, return the integer value
  // that is recieved when the character is subtracted by the ASCII value of '0'
  return (character > '9' ? character - 'a' + 10: character - '0');
}

char intdigittohex(int integer) {
  // If a value greater than 9 is recieved, then return the character recieved
  // by adding the integer to the ASCII value of 'a' and subtracting 10 so that
  // an input of 11 would return 'b' but an input of 7 would simply return '7'
  return (integer > 9 ? integer - 10 + 'a': integer + '0');
}

int intfrom16bit(string input) {
  int holder = 0;

  // Iterate through the string's characters adding 2^(15 - i) if the string
  // has character '1' at position i, so the first character being 1 would
  // would result in 2^15 being added to int holder
  for (int i = 0 ; i < 16; ++i) {
    holder += (input.at(i) - '0') * (int)pow(2, 15 - i);
  }
  return holder;
}

int intfrom32bithex(string input) {
  int holder = 0;

  // Iterate through the string's characters adding n * 16^(7-i) if the string
  // has character n (not 0) at position i, so the first character being 3 would
  // would result in 3* 16^7 being added to int holder
  for (int i = 0 ; i < 8; ++i) {
    holder += hexchartoint(input.at(i)) * (int)pow(16, 7 - i);
  }
  return holder;
}

string binaryfromint(int input) {
  string holder;
  int ourInteger = input;

  // While we can continue dividing by 2 without getting a remainder,
  // add the remainder of our integer / 2 as a character into our string holder,
  // then divide ourInteger by 2 before repeating the steps
  while (ourInteger > 0) {
    holder += (ourInteger % 2) + '0';
    ourInteger /= 2;
  }

  // Reverse string before returning

  for (int i = 0; i < holder.length() / 2; ++i)  {
    char temp;
    temp = holder[i];
    holder[i] = holder[holder.length() - i - 1];
    holder[holder.length() - i - 1] = temp;
  }
  return holder;
}

string hexadecimalfromint(int input) {
  string holder;
  int ourInteger = input;

  // While we can continue dividing by 16 without getting a remainder,
  // add the remainder of our integer / 16 as a hexadecimal character into
  // our string holder, then divide ourInteger by 16 before repeating the steps
  while (ourInteger > 0) {
    holder += intdigittohex(ourInteger % 16);
    ourInteger /= 16;
  }

  // Reverse string before returning

  for (int i = 0; i < holder.length() / 2; ++i)  {
    char temp;
    temp = holder[i];
    holder[i] = holder[holder.length() - i - 1];
    holder[holder.length() - i - 1] = temp;
  }
  return holder;
}

string basenaddition(string first, string second, int n) {
  string holder;
  int firstInt = 0;
  int secondInt = 0;
  int sum;

  // Convert first string into integer value
  for (int i = 0 ; i < first.length(); ++i) {
    firstInt += (first.at(i) - '0') * (int)pow(n, first.length() - i - 1);
  }

  // Convert second string into integer value
  for (int i = 0; i < second.length(); ++i) {
    secondInt += (second.at(i) - '0') * (int)pow(n, second.length() - i - 1);
  }

  // Perform the addition
  sum = firstInt + secondInt;

  //Convert the integer sum back into the respective base n form
  while (sum > 0) {
    holder += (sum % n) + '0';
    sum /= n;
  }

  // Reverse the string before returning
  for (int i = 0; i < holder.length() / 2; ++i)  {
    char temp;
    temp = holder[i];
    holder[i] = holder[holder.length() - i - 1];
    holder[holder.length() - i - 1] = temp;
  }

  return holder;
}

string hexaddition(string first, string second) {
  string holder;
  int firstInt = 0;
  int secondInt = 0;
  int sum;

  // Convert first string into integer value
  for (int i = 0 ; i < first.length(); ++i) {
    first.at(i) = std::tolower(first.at(i));
    if (first.at(i) > '9') {
      firstInt += (first.at(i) - 'a' + 10) * (int)pow(16, first.length() - i - 1);
    } else {
      firstInt += (first.at(i) - '0') * (int)pow(16, first.length() - i - 1);
    }
  }

  // Convert second string into integer value
  for (int i = 0; i < second.length(); ++i) {
    second.at(i) = std::tolower(second.at(i));
    if (second.at(i) > '9') {
      secondInt += (second.at(i) - 'a' + 10) * (int)pow(16, second.length() - i - 1);
    } else {
      secondInt += (second.at(i) - '0') * (int)pow(16, second.length() - i - 1);
    }
  }

  // Perform the addition
  sum = firstInt + secondInt;

  //Convert the integer sum back into the respective base n form
  while (sum > 0) {
    holder += (sum % 16) > 9 ? (sum % 16) - 10 + 'a': (sum % 16) + '0' ;
    sum /= 16;
  }

  // Reverse the string before returning
  for (int i = 0; i < holder.length() / 2; ++i)  {
    char temp;
    temp = holder[i];
    holder[i] = holder[holder.length() - i - 1];
    holder[holder.length() - i - 1] = temp;
  }

  return holder;
}

string hexmultiplication(string first, string second) {
  int holder = 0;
  string product;
  for(int i = second.length() - 1; i >= 0; --i) {
    holder = hexchartoint(second.at(i)) * hexchartoint(first.at(0)) + holder;
    product = intdigittohex(holder % 16) + product;
    holder = holder / 16;
  }
  if (intdigittohex(holder != '0')) {product = intdigittohex(holder) + product;}
  return product;
}
