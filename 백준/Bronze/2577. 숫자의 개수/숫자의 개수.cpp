#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, c;
  cin >> a >> b >> c;

  string str = to_string(a * b * c);
  vector<int> v(10, 0);

  for (char c : str) {
    ++v[c - '0'];
  }

  for (int i : v) {
    cout << i << "\n";
  }

  return 0;
}