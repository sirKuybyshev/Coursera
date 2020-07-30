#include <algorithm>
#include <iostream>
#include <string>

using namespace std;



int main() {
  string mainPart, leftPart;
  char ch;
  int n;
  cin >> mainPart;
  cin >> n;
  for (int i = 0; i < n; i++) {
    leftPart += '(';
    mainPart += ")";
    mainPart += " ";
    cin >> ch;
    mainPart += ch;
    mainPart += " ";
    cin >> ch;
    mainPart += ch;
  }
  cout << leftPart + mainPart;
  return 0;
}