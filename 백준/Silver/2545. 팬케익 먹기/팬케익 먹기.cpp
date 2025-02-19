#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    array<int64_t, 3> cake;
    int64_t d;
    cin >> cake[0] >> cake[1] >> cake[2] >> d;

    sort(cake.begin(), cake.end());
    int64_t sum = accumulate(cake.begin(), cake.end(), 0ll) - d;
    cake[0] = min(sum / 3, cake[0]);
    sum -= cake[0];
    cake[1] = min(sum / 2, cake[1]);
    cake[2] = sum - cake[1];

    cout << cake[0] * cake[1] * cake[2] << "\n";
  }

  return 0;
}