#include <bits/stdc++.h>
using namespace std;

deque<tuple<int, int>> dq;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int n, m;
    cin >> n >> m;

    dq.clear();

    for (int j = 0; j < n; ++j) {
      int x;
      cin >> x;
      dq.push_back({x, j});
    }

    int count = 0;
    while (!dq.empty()) {
      int now_num = get<0>(dq.front());
      int now_index = get<1>(dq.front());
      dq.pop_front();

      bool result = true;
      for (auto& t : dq) {
        if (get<0>(t) > now_num) {
          dq.push_back({now_num, now_index});
          result = false;
          break;
        }
      }

      if (!result) {
        continue;
      }

      ++count;
      if (now_index == m) {
        cout << count << "\n";
      }
    }
  }

  return 0;
}