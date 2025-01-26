#include <bits/stdc++.h>
using namespace std;

constexpr int kMax = 1000000 + 1;
array<int, kMax> divs{};
array<int, kMax> muls{};
array<bool, kMax> exist{};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> v(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    exist[v[i]] = true;
  }

  vector<int> sorted_v = v;
  sort(sorted_v.begin(), sorted_v.end());

  for (int i : sorted_v) {
    for (int j = i; j < kMax; j += i) {
      ++divs[j];

      if (j != i && exist[j]) {
        ++muls[i];
      }
    }
  }

  for (int i : v) {
    cout << muls[i] - divs[i] + 1 << " ";
  }

  return 0;
}