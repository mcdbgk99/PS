#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = max(1, n - static_cast<int>(to_string(n).length()) * 9); i < n;
       ++i) {
    int result = i;
    for (char c : to_string(i)) {
      result += c - '0';
    }

    if (result == n) {
      cout << i;
      return 0;
    }
  }

  cout << 0;

  return 0;
}