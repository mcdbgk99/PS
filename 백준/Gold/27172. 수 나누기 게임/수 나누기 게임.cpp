#include <bits/stdc++.h>
using namespace std;

constexpr int kMax = 1000000 + 1;
array<int, kMax> divs{};
array<int, kMax> muls{};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> v(n);
  bitset<kMax> bs;

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    bs[v[i]] = 1;
  }

  for (int i = 1; i < kMax; ++i) {
    if (!bs[i]) continue;

    for (int j = i; j < kMax; j += i) {
      ++divs[j];
      if (j != i && bs[j]) {
        ++muls[i];
      }
    }
  }

  for (int i : v) {
    cout << muls[i] - divs[i] + 1 << " ";
  }

  return 0;
}