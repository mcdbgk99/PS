#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, v;
  cin >> a >> b >> v;

  if (v == a) {
    cout << 1;
    return 0;
  }

  int day = (v - b - 1) / (a - b);
  cout << day + 1;

  return 0;
}