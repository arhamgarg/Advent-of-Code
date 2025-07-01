#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
  ifstream inputFile("input");
  string dimensions;
  int totalPaper = 0;
  int totalRibbon = 0;

  while (getline(inputFile, dimensions)) {
    int l, w, h;
    char x;
    stringstream ss(dimensions);
    ss >> l >> x >> w >> x >> h;

    int side1 = l * w;
    int side2 = w * h;
    int side3 = h * l;
    int surfaceArea = 2 * side1 + 2 * side2 + 2 * side3;
    int slack = min({side1, side2, side3});
    totalPaper += surfaceArea + slack;

    vector<int> dims = {l, w, h};
    sort(dims.begin(), dims.end());
    int perimeter = 2 * (dims[0] + dims[1]);
    int volume = l * w * h;
    totalRibbon += perimeter + volume;
  }

  cout << totalPaper << "\n";
  cout << totalRibbon << "\n";

  return 0;
}
