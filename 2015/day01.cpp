#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
  ifstream inputFile("input");
  string line;
  getline(inputFile, line);
  int floor = 0;
  int basement = -1;

  for (int i = 0; i < line.length(); ++i) { // ++i avoids a temporary copy
    floor += (line[i] == '(')
                 ? 1
                 : -1; // '(' is a character literal, "(" is a string literal

    if (floor < 0 && basement == -1) {
      basement = i + 1;
    }
  }

  cout << floor << "\n";
  cout << basement << "\n";

  return 0;
}
