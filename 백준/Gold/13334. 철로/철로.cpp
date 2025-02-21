#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<pair<i64, i64>> v(n);
  vector<i64> starts, ends;
  starts.reserve(n);
  ends.reserve(n);

  for (int i = 0; i < n; ++i) {
    i64 h, o;
    cin >> h >> o;
    v[i] = {min(h, o), max(h, o)};
  }

  i64 d;
  cin >> d;

  for (auto& p : v) {
    if (p.second - p.first > d) {
      continue;
    }

    starts.push_back(p.second - d);
    ends.push_back(p.first);
  }

  sort(starts.begin(), starts.end());
  sort(ends.begin(), ends.end());

  int result = 0, s = 0, e = starts.size();

  while (s < e) {
    i64 x = ends[s];
    result = max<int>(result, upper_bound(starts.begin(), starts.end(), x) -
                                  starts.begin() - s);

    int i = s;
    while (i < e && ends[i] == x) {
      ++i;
    }
    s = i;
  }

  cout << result;

  return 0;
}