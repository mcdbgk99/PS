#include <bits/stdc++.h>
using namespace std;

struct Data {
  int sum;
  int left;
  int right;
};

vector<int> v;
vector<Data> sums;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int w, n;
  cin >> w >> n;

  v.resize(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int sum = v[i] + v[j];
      sums.push_back({sum, i, j});
    }
  }

  sort(sums.begin(), sums.end(),
       [&](const Data& a, const Data& b) { return a.sum < b.sum; });

  bool found = false;
  int left = 0;
  int right = sums.size() - 1;
  while (left < right) {
    if (found) {
      break;
    }

    int current_sum = sums[left].sum + sums[right].sum;

    if (current_sum == w) {
      int a = sums[left].left;
      int b = sums[left].right;
      int c = sums[right].left;
      int d = sums[right].right;

      if (a != c && a != d && b != c && b != d) {
        found = true;
        break;
      }

      ++left;
    } else if (current_sum < w) {
      ++left;
    } else {
      --right;
    }
  }

  cout << (found ? "YES" : "NO");

  return 0;
}