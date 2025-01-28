#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> fg_cost(n);
  vector<int> bg_cost(n);

  for (int i = 0; i < n; ++i) {
    cin >> fg_cost[i];
  }

  for (int i = 0; i < n; ++i) {
    cin >> bg_cost[i];
  }

  vector<int> dp(accumulate(bg_cost.begin(), bg_cost.end(), 0) + 1, 0);

  for (int i = 0; i < n; ++i) {
    for (int j = dp.size() - 1; j >= bg_cost[i]; --j) {
      dp[j] = max(dp[j], dp[j - bg_cost[i]] + fg_cost[i]);
    }
  }

  for (int i = 0; i < dp.size(); ++i) {
    if (dp[i] >= m) {
      cout << i;
      return 0;
    }
  }

  return 0;
}