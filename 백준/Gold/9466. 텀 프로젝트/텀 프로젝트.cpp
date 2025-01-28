#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> v(n + 1);

    for (int i = 1; i <= n; ++i) {
      cin >> v[i];
    }

    vector<int> visited(n + 1, 0);
    vector<int> path_index(n + 1, -1);

    int count = 0;

    for (int i = 1; i <= n; ++i) {
      if (visited[i] != 0) {
        continue;
      }

      vector<int> path;
      deque<tuple<int, bool>> dq;

      dq.push_back({i, false});

      while (!dq.empty()) {
        auto [now_node, done] = dq.back();
        dq.pop_back();

        if (!done) {
          if (visited[now_node] != 0) {
            continue;
          }

          visited[now_node] = 1;
          path_index[now_node] = path.size();
          path.push_back(now_node);
          dq.push_back({now_node, true});

          int new_node = v[now_node];

          if (visited[new_node] == 0) {
            dq.push_back({new_node, false});
          } else if (visited[new_node] == 1) {
            count += path.size() - path_index[new_node];
          }
        } else {
          if (visited[now_node] == 1) {
            visited[now_node] = 2;
            path.pop_back();
          }
        }
      }
    }

    cout << n - count << "\n";
  }

  return 0;
}