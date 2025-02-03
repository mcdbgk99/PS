#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<array<int, 2>> gem(n);
  vector<int> knapsack(k);

  for (int i = 0; i < n; ++i) {
    cin >> gem[i][0] >> gem[i][1];
  }
  sort(gem.begin(), gem.end(), [](array<int, 2>& left, array<int, 2>& right) {
    return left[0] < right[0];
  });

  for (int i = 0; i < k; ++i) {
    cin >> knapsack[i];
  }
  sort(knapsack.begin(), knapsack.end());

  int64_t result = 0;
  int next_index = 0;
  priority_queue<int> pq;

  for (int i = 0; i < k; ++i) {
    for (int j = next_index; j < n; ++j) {
      if (gem[j][0] > knapsack[i]) {
        break;
      }

      next_index = j + 1;
      pq.push({gem[j][1]});
    }

    while (!pq.empty()) {
      int value = pq.top();
      pq.pop();

      result += value;
      break;
    }
  }

  cout << result;

  return 0;
}