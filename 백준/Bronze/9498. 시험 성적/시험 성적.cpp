#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  if (n >= 90 && n <= 100) {
    cout << "A";
  } else if (n >= 80 && n <= 89) {
    cout << "B";
  } else if (n >= 70 && n <= 79) {
    cout << "C";
  } else if (n >= 60 && n <= 69) {
    cout << "D";
  } else {
    cout << "F";
  }

  return 0;
}