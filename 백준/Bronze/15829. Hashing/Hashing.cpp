#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int l;
  cin >> l;
  string str;
  cin >> str;

  uint64_t result = 0;
  for (int i = 0; i < str.length(); ++i) {
    uint64_t mul = 1;
    for (int j = 0; j < i; ++j) {
      mul *= 31;
      mul %= 1234567891;
    }
    result += (str[i] - 96) * mul;
  }

  cout << result % 1234567891;

  return 0;
}