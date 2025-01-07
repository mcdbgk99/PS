#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string str;
  cin >> str;

  int64_t result = 0;
  bool last_plus = true;

  while (!str.empty()) {
    size_t plus = str.find('+');
    size_t minus = str.find('-');
    int num;
    bool next_plus = true;

    if (plus == string::npos && minus == string::npos) {
      num = stoi(str.substr(0, str.length()));
      str.clear();
    } else {
      size_t next_sign = min(plus, minus);
      num = stoi(str.substr(0, next_sign));
      next_plus = (str[next_sign] == '+');
      str = str.substr(next_sign + 1, str.length() - next_sign - 1);
    }

    if (last_plus) {
      result += num;
    } else {
      result -= num;
    }

    last_plus &= next_plus;
  }

  cout << result;

  return 0;
}