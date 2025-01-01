#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  cout << setfill('0');
  for (int i = 0; i < t; ++i) {
    int h, w, n;
    cin >> h >> w >> n;
    cout << setw(0) << (n - 1) % h + 1 << setw(2) << (n - 1) / h + 1 << "\n";
  }

  return 0;
}