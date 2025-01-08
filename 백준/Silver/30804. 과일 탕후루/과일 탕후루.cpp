#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int>> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int fruit_type = 0;
  int fruit_count = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;

    if (fruit_type != 0) {
      if (fruit_type != x) {
        v.push_back({fruit_type, fruit_count});
        fruit_type = x;
        fruit_count = 1;
      } else {
        ++fruit_count;
      }
    } else {
      fruit_type = x;
      ++fruit_count;
    }
  }
  v.push_back({fruit_type, fruit_count});

  int result = 0;

  if (v.size() > 1) {
    unordered_map<int, int> m;
    m[get<0>(v[0])] += get<1>(v[0]);

    int left = 0;
    int right = 1;
    while (true) {
      if (m.size() > 2) {
        m[get<0>(v[left])] -= get<1>(v[left]);
        if (m[get<0>(v[left])] <= 0) {
          m.erase(get<0>(v[left]));
        }

        ++left;
        continue;
      }

      int sum = 0;
      for (auto& p : m) {
        sum += p.second;
      }
      result = max(result, sum);

      if (right >= v.size()) {
        break;
      }

      m[get<0>(v[right])] += get<1>(v[right]);
      ++right;
    }
  } else {
    result = get<1>(v[0]);
  }

  cout << result;

  return 0;
}