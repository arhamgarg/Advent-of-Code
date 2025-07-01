#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
  ifstream inputFile("input");
  string line;
  int totalFuel = 0;

  while (getline(inputFile, line)) {
    int mass = stoi(line);

    int fuel = mass / 3 - 2;

    if (fuel <= 0)
      continue;

    totalFuel += fuel;

    while (true) {
      fuel = fuel / 3 - 2;

      if (fuel <= 0)
        break;

      totalFuel += fuel;
    }
  }

  cout << totalFuel << "\n";

  return 0;
}
