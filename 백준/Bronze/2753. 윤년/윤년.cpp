#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  cout << (n % 4 != 0 || (n % 100 == 0 && n % 400 != 0) ? 0 : 1);

  return 0;
}