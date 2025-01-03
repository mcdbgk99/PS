#include <bits/stdc++.h>
using namespace std;

vector<int> v(30 + 1, 0);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  if (n == 0) {
    cout << 0;
    return 0;
  }

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++v[x];
  }

  int cut = floor(static_cast<double>(n) * 0.15 + 0.5);

  int cut_down = 0;
  for (int i = 1; i < v.size(); ++i) {
    if (cut_down == cut) {
      break;
    }

    if (v[i] == 0) {
      continue;
    }

    if (v[i] <= cut - cut_down) {
      cut_down += v[i];
      v[i] = 0;
    }

    if (v[i] > cut - cut_down) {
      v[i] -= cut - cut_down;
      cut_down = cut;
    }
  }

  int cut_up = 0;
  for (int i = v.size() - 1; i >= 1; --i) {
    if (cut_up == cut) {
      break;
    }

    if (v[i] == 0) {
      continue;
    }

    if (v[i] <= cut - cut_up) {
      cut_up += v[i];
      v[i] = 0;
    }

    if (v[i] > cut - cut_up) {
      v[i] -= cut - cut_up;
      cut_up = cut;
    }
  }

  int64_t total = 0;
  for (int i = 1; i < v.size(); ++i) {
    total += v[i] * i;
  }

  cout << floor(static_cast<double>(total) / (n - cut * 2) + 0.5);

  return 0;
}