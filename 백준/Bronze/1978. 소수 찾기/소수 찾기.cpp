#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  auto is_prime = [](int x)->bool {
    if (x == 1) {
      return false;
    }

    for (int i = 2; i <= x / 2; ++i) {
      if (x % i == 0) {
        return false;
      }
    }

    return true;
  };

  int result = 0;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (is_prime(x)) {
      ++result;
    }
  }

  cout << result;

  return 0;
}