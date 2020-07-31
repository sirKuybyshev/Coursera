#include <iostream>
#include <string>

using namespace std;

int main() {
  string mainPart, leftPart;
  char type;
  int numb;
  int n;
  bool isNeeded = false;
  cin >> mainPart;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> type;
    if (((type == '*') || (type == '/')) && isNeeded) {
      leftPart += '(';
      mainPart += ")";
    }
    if ((type == '+') || (type == '-')) {
      isNeeded = true;
    } else {
      isNeeded = false;
    }
    mainPart += " ";
    mainPart += type;
    mainPart += " ";
    cin >> numb;
    mainPart += to_string(numb);
  }
  cout << leftPart + mainPart;
  return 0;
}