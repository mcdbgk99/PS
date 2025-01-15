#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  v.resize(m, vector<int>(n, 0));

  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      cin >> v[x][y];
    }
  }

  int result = INT32_MIN;
  vector<int> mask(n * m, 0);
  fill(mask.end() - k, mask.end(), 1);

  do {
    vector<tuple<int, int>> selected_index;

    for (int i = 0; i < mask.size(); ++i) {
      if (mask[i] == 1) {
        selected_index.push_back({i % m, i / m});
      }
    }

    bool skip = false;

    for (int i = 0; i < selected_index.size(); ++i) {
      for (int j = i + 1; j < selected_index.size(); ++j) {
        if (abs(get<0>(selected_index[i]) - get<0>(selected_index[j])) +
                abs(get<1>(selected_index[i]) - get<1>(selected_index[j])) ==
            1) {
          skip = true;
          break;
        }
      }

      if (skip) {
        break;
      }
    }

    if (skip) {
      continue;
    }

    int sum = 0;
    for (auto& t : selected_index) {
      sum += v[get<0>(t)][get<1>(t)];
    }

    result = max(result, sum);
  } while (next_permutation(mask.begin(), mask.end()));

  cout << result;

  return 0;
}