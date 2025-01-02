#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> v;
vector<int> result;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  result.resize(n, 1);

  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    v.push_back({i, x, y});
  }

  sort(v.begin(), v.end(),
       [](tuple<int, int, int>& left, tuple<int, int, int>& right) {
         return get<1>(left) > get<1>(right);
       });

  for (int i = 0; i < n; ++i) {
    int current_w = get<1>(v[i]);
    int current_h = get<2>(v[i]);

    for (int j = 0; j < n; ++j) {
      int find_w = get<1>(v[j]);
      int find_h = get<2>(v[j]);
      if (i == j) {
        continue;
      }

      if (current_w >= find_w) {
        break;
      }

      if (current_w < find_w && current_h < find_h) {
        ++result[get<0>(v[i])];
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << result[i] << " ";
  }

  return 0;
}