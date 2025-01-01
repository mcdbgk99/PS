#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int l;
  cin >> l;
  string str;
  cin >> str;

  int64_t result = 0;
  for (int i = 0; i < str.length(); ++i) {
    result += (str[i] - 96) * pow(31, i);
  }

  cout << result % 1234567891;

  return 0;
}