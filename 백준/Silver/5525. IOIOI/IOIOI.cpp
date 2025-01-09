#include <bits/stdc++.h>
using namespace std;

string str;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  string p = "";
  for (int i = 0; i < n * 2 + 1; ++i) {
    p.append(i % 2 != 0 ? "O" : "I");
  }

  cin >> n >> str;

  int result = 0;

  while (!str.empty()) {
    size_t found = str.find(p);
    if (found == string::npos) {
      break;
    }

    ++result;
    str = str.substr(found + 1, str.length() - found - 1);
  }

  cout << result;

  return 0;
}