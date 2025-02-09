#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  vector<int> cards(m);
  vector<int> visited(m, 0);

  for (int i = 0; i < m; ++i) {
    cin >> cards[i];
  }

  sort(cards.begin(), cards.end());

  for (int i = 0; i < k; ++i) {
    int x;
    cin >> x;
    auto it = upper_bound(cards.begin(), cards.end(), x);
    int j = 0;
    while (visited[it - cards.begin() + j]) {
      ++j;
    }
    visited[it - cards.begin() + j] = 1;
    cout << *(it + j) << "\n";
  }

  return 0;
}