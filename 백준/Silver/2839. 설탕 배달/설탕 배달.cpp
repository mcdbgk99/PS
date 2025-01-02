#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  if (n == 4 || n == 7) {
    cout << -1;
    return 0;
  }

  int five = n;
  if (n % 5 != 0) {
    five += 5 - (n % 5);
    while (five % 2 != n % 2) {
      five += 5;
    }
  }

  cout << five / 5;

  return 0;
}