#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<tuple<int, int>> freq(8000 + 2);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  v.resize(n);

  for (int i = 0; i < freq.size(); ++i) {
    freq[i] = {0, i - 4000};
  }

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    ++get<0>(freq[v[i] + 4000]);
  }

  sort(v.begin(), v.end());
  sort(freq.begin(), freq.end(),
       [](tuple<int, int>& left, tuple<int, int>& right) {
         return get<0>(left) > get<0>(right) ||
                (get<0>(left) == get<0>(right) ? get<1>(left) < get<1>(right)
                                               : false);
       });

  cout << floor(static_cast<double>(accumulate(v.begin(), v.end(), 0)) / n +
                0.5)
       << "\n"
       << v[n / 2] << "\n"
       << (get<0>(freq[0]) == get<0>(freq[1]) ? get<1>(freq[1])
                                              : get<1>(freq[0]))
       << "\n"
       << v[n - 1] - v[0];

  return 0;
}
