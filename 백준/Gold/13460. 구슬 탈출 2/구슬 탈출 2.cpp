#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<string> v(n);
  tuple<int, int> red, blue, out;

  for (int y = 0; y < n; ++y) {
    cin >> v[y];
    for (int x = 0; x < m; ++x) {
      if (v[y][x] == 'R') {
        v[y][x] = '.';
        red = {y, x};
      } else if (v[y][x] == 'B') {
        v[y][x] = '.';
        blue = {y, x};
      } else if (v[y][x] == 'O') {
        out = {y, x};
      }
    }
  }

  vector<vector<vector<vector<int>>>> visited(
      n, vector<vector<vector<int>>>(
             m, vector<vector<int>>(n, vector<int>(m, 0))));
  deque<tuple<int, int, int, int, int>> dq;
  constexpr array<int, 4> pattern_y = {-1, 1, 0, 0};
  constexpr array<int, 4> pattern_x = {0, 0, -1, 1};

  visited[get<0>(red)][get<1>(red)][get<0>(blue)][get<1>(blue)] = 1;
  dq.push_back({get<0>(red), get<1>(red), get<0>(blue), get<1>(blue), 0});

  int result = -1;

  while (!dq.empty()) {
    auto [now_red_y, now_red_x, now_blue_y, now_blue_x, now_step] = dq.front();
    dq.pop_front();

    if (now_step > 10) {
      continue;
    }

    if (now_red_y == get<0>(out) && now_red_x == get<1>(out)) {
      if (now_blue_y == get<0>(out) && now_blue_x == get<1>(out)) {
        continue;
      } else {
        result = now_step;
        break;
      }
    }

    for (int i = 0; i < 4; ++i) {
      bool red_first;
      if (i == 0) {
        red_first = now_red_y < now_blue_y;
      } else if (i == 1) {
        red_first = now_red_y > now_blue_y;
      } else if (i == 2) {
        red_first = now_red_x < now_blue_x;
      } else {
        red_first = now_red_x > now_blue_x;
      }

      tuple<int, int> first = {now_red_y, now_red_x};
      tuple<int, int> second = {now_blue_y, now_blue_x};
      if (!red_first) {
        swap(first, second);
      }

      while (true) {
        tuple<int, int> new_first = {get<0>(first) + pattern_y[i],
                                     get<1>(first) + pattern_x[i]};
        if (v[get<0>(new_first)][get<1>(new_first)] == 'O') {
          first = new_first;
          break;
        }

        if (v[get<0>(new_first)][get<1>(new_first)] == '#') {
          break;
        }

        if (get<0>(new_first) == get<0>(second) &&
            get<1>(new_first) == get<1>(second)) {
          break;
        }

        first = new_first;
      }

      while (true) {
        tuple<int, int> new_second = {get<0>(second) + pattern_y[i],
                                      get<1>(second) + pattern_x[i]};

        if (v[get<0>(new_second)][get<1>(new_second)] == 'O') {
          second = new_second;
          break;
        }

        if (v[get<0>(new_second)][get<1>(new_second)] == '#') {
          break;
        }

        if (get<0>(new_second) == get<0>(first) &&
            get<1>(new_second) == get<1>(first)) {
          break;
        }

        second = new_second;
      }

      int new_red_y, new_red_x, new_blue_y, new_blue_x;
      if (red_first) {
        new_red_y = get<0>(first);
        new_red_x = get<1>(first);
        new_blue_y = get<0>(second);
        new_blue_x = get<1>(second);
      } else {
        new_blue_y = get<0>(first);
        new_blue_x = get<1>(first);
        new_red_y = get<0>(second);
        new_red_x = get<1>(second);
      }

      if (new_blue_y == get<0>(out) && new_blue_x == get<1>(out)) {
        continue;
      }

      if (new_red_y == get<0>(out) && new_red_x == get<1>(out)) {
        if (now_step + 1 <= 10) {
          cout << now_step + 1;
          return 0;
        }
      }

      if (visited[new_red_y][new_red_x][new_blue_y][new_blue_x]) {
        continue;
      }

      visited[new_red_y][new_red_x][new_blue_y][new_blue_x] = true;
      dq.push_back(
          {new_red_y, new_red_x, new_blue_y, new_blue_x, now_step + 1});
    }
  }

  cout << -1;

  return 0;
}