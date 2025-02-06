#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int h, w, c, d;
  cin >> h >> w >> c >> d;

  int min_nine = h * (h - 1) / 2;
  if (d < min_nine || d > h * w - min_nine) {
    cout << -1;
    return 0;
  }

  vector<int> v(h);
  iota(v.begin(), v.end(), 0);
  int remain = d - min_nine;
  for (int i = h - 1; i >= 0; --i) {
    int add = min(remain, w - h + 1 + i - v[i]);
    v[i] += add;
    remain -= add;
    if (remain <= 0) {
      break;
    }
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < v[i]; ++j) {
      cout << "9 ";
    }

    for (int j = 0; j < w - v[i]; ++j) {
      cout << "1 ";
    }

    cout << "\n";
  }

  return 0;
}