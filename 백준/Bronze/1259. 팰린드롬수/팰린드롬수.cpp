#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  while (true) {
    cin >> n;
    if (n == 0) {
      return 0;
    }

    bool result = true;
    string str = to_string(n);
    for (int i = 0; i < str.length() / 2; ++i) {
      if (str[i] != str[str.length() - 1 - i]) {
        result = false;
        break;
      }
    }

    cout << (result ? "yes\n" : "no\n");
  }

  return 0;
}