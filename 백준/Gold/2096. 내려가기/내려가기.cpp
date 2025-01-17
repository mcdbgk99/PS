#include <bits/stdc++.h>
using namespace std;

deque<vector<int>> dq;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  dq.push_back({0, 0, 0, 0, 0, 0});

  for (int i = 1; i <= n; ++i) {
    int a, b, c;
    cin >> a >> b >> c;

    dq.push_back({max(dq.front()[0], dq.front()[1]) + a,
                  max({dq.front()[0], dq.front()[1], dq.front()[2]}) + b,
                  max(dq.front()[1], dq.front()[2]) + c,
                  min(dq.front()[3], dq.front()[4]) + a,
                  min({dq.front()[3], dq.front()[4], dq.front()[5]}) + b,
                  min(dq.front()[4], dq.front()[5]) + c});
    dq.pop_front();
  }

  cout << max({dq.front()[0], dq.front()[1], dq.front()[2]}) << " "
       << min({dq.front()[3], dq.front()[4], dq.front()[5]});

  return 0;
}