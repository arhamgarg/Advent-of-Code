#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <utility>
using namespace std;

int main() {
  ifstream inputFile("input");
  string directions;
  getline(inputFile, directions);

  int x1 = 0, y1 = 0;
  int x2 = 0, y2 = 0;
  int x, y;

  set<pair<int, int>> visited;
  visited.insert({0, 0});

  for (int i = 0; i < directions.length(); i++) {
    char c = directions[i];

    x = (i % 2 == 0) ? x1 : x2;
    y = (i % 2 == 0) ? y1 : y2;

    if (c == '>')
      x++;
    else if (c == '<')
      x--;
    else if (c == '^')
      y++;
    else if (c == 'v')
      y--;

    visited.insert({x, y});
  }

  cout << visited.size() << "\n";

  return 0;
}
