#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int r, c, t;
  cin >> r >> c >> t;

  vector<vector<int>> v(r, vector<int>(c));
  int cleaner_top = -1;
  int cleaner_bottom = -1;

  for (int y = 0; y < r; ++y) {
    for (int x = 0; x < c; ++x) {
      cin >> v[y][x];
      if (v[y][x] == -1) {
        if (cleaner_top == -1) {
          cleaner_top = y;
        } else {
          cleaner_bottom = y;
        }
      }
    }
  }

  array<int, 4> pattern_y = {-1, 1, 0, 0};
  array<int, 4> pattern_x = {0, 0, -1, 1};

  for (int i = 0; i < t; ++i) {
    vector<vector<int>> diffuse(r, vector<int>(c, 0));

    for (int y = 0; y < r; ++y) {
      for (int x = 0; x < c; ++x) {
        if (v[y][x] > 0) {
          int count = 0;
          int diffused = v[y][x] / 5;

          for (int i = 0; i < 4; ++i) {
            int new_y = y + pattern_y[i];
            int new_x = x + pattern_x[i];

            if (new_y < 0 || new_y >= r || new_x < 0 || new_x >= c) {
              continue;
            }

            if (v[new_y][new_x] == -1) {
              continue;
            }

            ++count;
            diffuse[new_y][new_x] += diffused;
          }

          diffuse[y][x] += v[y][x] - count * diffused;
        } else if (v[y][x] == -1) {
          diffuse[y][x] = -1;
        }
      }
    }
    v = diffuse;

    vector<tuple<int, int>> clean;

    for (int x = 1; x < c; ++x) {
      clean.push_back({cleaner_top, x});
    }

    for (int y = cleaner_top - 1; y >= 0; --y) {
      clean.push_back({y, c - 1});
    }

    for (int x = c - 2; x >= 0; --x) {
      clean.push_back({0, x});
    }

    for (int y = 1; y < cleaner_top; ++y) {
      clean.push_back({y, 0});
    }

    for (int i = clean.size() - 1; i > 0; --i) {
      v[get<0>(clean[i])][get<1>(clean[i])] =
          v[get<0>(clean[i - 1])][get<1>(clean[i - 1])];
    }
    v[get<0>(clean.front())][get<1>(clean.front())] = 0;

    clean.clear();

    for (int x = 1; x < c; ++x) {
      clean.push_back({cleaner_bottom, x});
    }

    for (int y = cleaner_bottom + 1; y < r; ++y) {
      clean.push_back({y, c - 1});
    }

    for (int x = c - 2; x >= 0; --x) {
      clean.push_back({r - 1, x});
    }

    for (int y = r - 2; y > cleaner_bottom; --y) {
      clean.push_back({y, 0});
    }

    for (int i = clean.size() - 1; i > 0; --i) {
      v[get<0>(clean[i])][get<1>(clean[i])] =
          v[get<0>(clean[i - 1])][get<1>(clean[i - 1])];
    }
    v[get<0>(clean.front())][get<1>(clean.front())] = 0;
  }

  int result = 0;
  for (int y = 0; y < r; ++y) {
    for (int x = 0; x < c; ++x) {
      if (v[y][x] != -1) {
        result += v[y][x];
      }
    }
  }

  cout << result;

  return 0;
}