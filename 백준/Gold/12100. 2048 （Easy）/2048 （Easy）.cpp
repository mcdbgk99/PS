#include <bits/stdc++.h>
using namespace std;

void Dfs(vector<vector<int>> v, int& best_score, int step) {
  if (step == 5) {
    for (int y = 0; y <= v.size() - 1; ++y) {
      for (int x = 0; x <= v.size() - 1; ++x) {
        best_score = max(best_score, v[x][y]);
      }
    }

    return;
  }

  vector<vector<int>> temp;

  temp.assign(v.size(), vector<int>(v.size(), 0));
  for (int x = 0; x < v.size(); ++x) {
    int idx = 0;
    int prev = -1;

    for (int y = idx; y < v.size(); ++y) {
      if (v[x][y] == 0) {
        continue;
      }

      if (prev != -1) {
        if (prev == v[x][y]) {
          temp[x][idx++] = prev * 2;
          prev = -1;
        } else {
          temp[x][idx++] = prev;
          prev = v[x][y];
        }
      } else {
        prev = v[x][y];
      }
    }

    if (prev != -1) {
      temp[x][idx] = prev;
    }
  }
  Dfs(temp, best_score, step + 1);

  temp.assign(v.size(), vector<int>(v.size(), 0));
  for (int x = 0; x < v.size(); ++x) {
    int idx = v.size() - 1;
    int prev = -1;

    for (int y = idx; y >= 0; --y) {
      if (v[x][y] == 0) {
        continue;
      }

      if (prev != -1) {
        if (prev == v[x][y]) {
          temp[x][idx--] = prev * 2;
          prev = -1;
        } else {
          temp[x][idx--] = prev;
          prev = v[x][y];
        }
      } else {
        prev = v[x][y];
      }
    }

    if (prev != -1) {
      temp[x][idx] = prev;
    }
  }
  Dfs(temp, best_score, step + 1);

  temp.assign(v.size(), vector<int>(v.size(), 0));
  for (int y = 0; y < v.size(); ++y) {
    int idx = 0;
    int prev = -1;

    for (int x = idx; x < v.size(); ++x) {
      if (v[x][y] == 0) {
        continue;
      }

      if (prev != -1) {
        if (prev == v[x][y]) {
          temp[idx++][y] = prev * 2;
          prev = -1;
        } else {
          temp[idx++][y] = prev;
          prev = v[x][y];
        }
      } else {
        prev = v[x][y];
      }
    }

    if (prev != -1) {
      temp[idx][y] = prev;
    }
  }
  Dfs(temp, best_score, step + 1);

  temp.assign(v.size(), vector<int>(v.size(), 0));
  for (int y = 0; y < v.size(); ++y) {
    int idx = v.size() - 1;
    int prev = -1;

    for (int x = idx; x >= 0; --x) {
      if (v[x][y] == 0) {
        continue;
      }

      if (prev != -1) {
        if (prev == v[x][y]) {
          temp[idx--][y] = prev * 2;
          prev = -1;
        } else {
          temp[idx--][y] = prev;
          prev = v[x][y];
        }
      } else {
        prev = v[x][y];
      }
    }

    if (prev != -1) {
      temp[idx][y] = prev;
    }
  }
  Dfs(temp, best_score, step + 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<int>> v(n, vector<int>(n));

  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      cin >> v[x][y];
    }
  }

  int result = 0;
  Dfs(v, result, 0);

  cout << result;

  return 0;
}