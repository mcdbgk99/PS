#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
queue<tuple<int, int, int>> q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  v.resize(n + 1, vector<int>(n + 1, 0));

  for (int y = 1; y <= n; ++y) {
    for (int x = 1; x <= n; ++x) {
      int a;
      cin >> a;
      v[x][y] = a + v[x - 1][y] + v[x][y - 1] - v[x - 1][y - 1];
    }
  }

  auto is_one_colored = [](int start_x, int start_y, int size) -> int {
    int sum = v[start_x + size - 1][start_y + size - 1] -
              v[start_x - 1][start_y + size - 1] -
              v[start_x + size - 1][start_y - 1] + v[start_x - 1][start_y - 1];

    return (sum == 0 ? 0 : (sum == size * size ? 1 : -1));
  };

  array<int, 2> result = {0, 0};

  q.push({1, 1, n});

  while (!q.empty()) {
    int now_x = get<0>(q.front());
    int now_y = get<1>(q.front());
    int now_size = get<2>(q.front());
    q.pop();

    int color = is_one_colored(now_x, now_y, now_size);
    if (color != -1) {
      ++result[color];
    } else {
      int new_size = now_size / 2;
      if (new_size == 0) {
        continue;
      }

      for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
          q.push({now_x + i * new_size, now_y + j * new_size, new_size});
        }
      }
    }
  }

  cout << result[0] << "\n" << result[1];

  return 0;
}