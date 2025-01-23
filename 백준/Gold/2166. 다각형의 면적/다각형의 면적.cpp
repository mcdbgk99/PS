// https://mathworld.wolfram.com/PolygonArea.html

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<tuple<int64_t, int64_t>> v;

  for (int i = 0; i < n; ++i) {
    int64_t x, y;
    cin >> x >> y;
    v.push_back({x, y});
  }

  int64_t sum = 0;
  for (int i = 0; i < n; ++i) {
    int j = (i + 1) % n;
    sum += get<0>(v[i]) * get<1>(v[j]);
    sum -= get<1>(v[i]) * get<0>(v[j]);
  }

  cout.precision(1);
  cout << fixed << static_cast<double>(abs(sum)) / 2.0;

  return 0;
}