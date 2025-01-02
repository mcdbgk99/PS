#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, string>> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  v.resize(n);

  for (int i = 0; i < n; ++i) {
    get<1>(v[i]) = i;
    cin >> get<0>(v[i]) >> get<2>(v[i]);
  }

  sort(v.begin(), v.end(),
       [](tuple<int, int, string>& left, tuple<int, int, string>& right) {
         return get<0>(left) < get<0>(right) ||
                (get<0>(left) == get<0>(right) ? get<1>(left) < get<1>(right)
                                               : false);
       });

  for (auto& t : v) {
    cout << get<0>(t) << " " << get<2>(t) << "\n";
  }

  return 0;
}