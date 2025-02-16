#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int h, w;
  cin >> h >> w;

  vector<int64_t> a(h - 1), b(w), c(h), d(w - 1);
  array<int64_t, 3> sum = {0, 0, 0};

  for (int i = 0; i < h - 1; ++i) {
    cin >> a[i];
    sum[0] += a[i];
  }

  for (int i = 0; i < w; ++i) {
    cin >> b[i];
  }

  for (int i = 0; i < h; ++i) {
    cin >> c[i];
    sum[1] += c[i];
  }

  for (int i = 0; i < w - 1; ++i) {
    cin >> d[i];
    sum[2] += d[i];
  }

  int64_t result = (w - 1) * sum[1] + h * sum[2] + (h - 1) * b[0] + sum[0];

  int n = h - 1;
  int m = w - 1;

  vector<int64_t> v_to_h(n), h_to_v(m);

  for (int i = 0; i < h - 1; ++i) {
    v_to_h[i] = c[i + 1] - a[i];
  }

  for (int j = 0; j < m; ++j) {
    h_to_v[j] = d[j] - b[j + 1];
  }

  sort(v_to_h.begin(), v_to_h.end());
  sort(h_to_v.begin(), h_to_v.end());

  vector<int64_t> psum(m + 1, 0);

  for (int j = 0; j < m; ++j) {
    psum[j + 1] = psum[j] + h_to_v[j];
  }

  int64_t sum_cost = 0;

  for (int i = 0; i < v_to_h.size(); ++i) {
    int64_t j = v_to_h[i];
    int64_t idx =
        lower_bound(h_to_v.begin(), h_to_v.end(), -j + 1) - h_to_v.begin();
    int64_t cnt = m - idx;
    if (cnt > 0) {
      sum_cost += cnt * j + (psum[m] - psum[idx]);
    }
  }

  result -= sum_cost;
  cout << result;

  return 0;
}