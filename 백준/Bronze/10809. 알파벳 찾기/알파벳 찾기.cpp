#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string str;
  cin >> str;

  for (char c = 'a'; c <= 'z'; ++c) {
    size_t index = str.find(c);
    if (index != string::npos) {
      cout << index;
    } else {
      cout << -1;
    }

    if (c != 'z') {
      cout << " ";
    }
  }

  return 0;
}