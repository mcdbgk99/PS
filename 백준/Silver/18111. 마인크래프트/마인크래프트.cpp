#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, b;
  cin >> n >> m >> b;

  v.resize(m, vector<int>(n));

  int64_t sum = 0;

  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      cin >> v[x][y];
      sum += v[x][y];
    }
  }

  tuple<int64_t, int> result = {INT64_MAX, 0};

  for (int i = min(static_cast<int>(sum / m * n + 1), 256); i >= 0; --i) {
    int64_t used_time = 0;
    int temp_inventory = b;

    for (int y = 0; y < n; ++y) {
      for (int x = 0; x < m; ++x) {
        if (v[x][y] < i) {
          temp_inventory -= i - v[x][y];
          used_time += i - v[x][y];
        } else if (v[x][y] > i) {
          temp_inventory += v[x][y] - i;
          used_time += (v[x][y] - i) * 2;
        }
      }
    }

    if (temp_inventory >= 0 && get<0>(result) >= used_time) {
      if (get<0>(result) == used_time) {
        get<1>(result) = max(get<1>(result), i);
      } else {
        get<1>(result) = i;
      }
      get<0>(result) = used_time;
    }
  }

  cout << get<0>(result) << " " << get<1>(result);

  return 0;
}