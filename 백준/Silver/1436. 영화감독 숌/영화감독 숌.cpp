#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int i = 665;
  int index = 0;
  while (true) {
    ++i;
    string str = to_string(i);
    if (str.find("666") != string::npos) {
      ++index;
    }

    if (index == n) {
      cout << i;
      return 0;
    }
  }

  return 0;
}