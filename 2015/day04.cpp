#include <iostream>
#include <md5.h>
#include <string>
using namespace std;

int main() {
  string input = "iwrupvqb";
  int number = 0;

  while (true) {
    string hashInput = input + to_string(number);
    string hash = md5(hashInput);

    if (hash.substr(0, 5) == "00000") {
      cout << number << "\n";
      break;
    }

    number++;
  }

  return 0;
}
