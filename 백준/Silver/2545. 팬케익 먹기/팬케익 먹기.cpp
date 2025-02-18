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

    while (d--) {
      --(*max_element(cake.begin(), cake.end()));
    }

    cout << cake[0] * cake[1] * cake[2] << "\n";
  }

  return 0;
}