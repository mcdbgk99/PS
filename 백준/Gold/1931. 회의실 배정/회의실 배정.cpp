#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<tuple<int, int>> v(n);

  for (int i = 0; i < n; ++i) {
    cin >> get<0>(v[i]) >> get<1>(v[i]);
  }

  sort(v.begin(), v.end(), [](tuple<int, int>& left, tuple<int, int>& right) {
    return get<1>(left) < get<1>(right) ||
           (get<1>(left) == get<1>(right) ? get<0>(left) < get<0>(right)
                                          : false);
  });

  int last_end = 0;
  int result = 0;

  for (auto& t : v) {
    if (get<0>(t) >= last_end) {
      ++result;
      last_end = get<1>(t);
    }
  }

  cout << result;

  return 0;
}