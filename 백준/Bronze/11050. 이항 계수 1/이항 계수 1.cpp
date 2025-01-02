#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> combination_table(11, vector<int>(11));

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 0; i < combination_table.size(); ++i) {
    combination_table[i][0] = 1;

    for (int j = 1; j <= i; ++j) {
      combination_table[i][j] =
          combination_table[i - 1][j - 1] + combination_table[i - 1][j];
    }
  }

  int n, k;
  cin >> n >> k;
  cout << combination_table[n][k];

  return 0;
}