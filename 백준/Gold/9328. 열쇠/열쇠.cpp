#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int h, w;
    cin >> h >> w;

    vector<string> v(h + 2);
    v[0].resize(w + 2, '.');
    v[h + 1].resize(w + 2, '.');

    for (int i = 1; i <= h; ++i) {
      string str;
      cin >> str;
      v[i] = "." + str + ".";
    }

    unordered_set<char> keys;
    string str;
    cin >> str;
    for (char c : str) {
      if (c == '0') {
        break;
      }

      keys.insert(c);
    }

    int result = 0;
    constexpr array<int, 4> pattern_y = {-1, 1, 0, 0};
    constexpr array<int, 4> pattern_x = {0, 0, -1, 1};
    vector<vector<int>> visited(h + 2, vector<int>(w + 2, 0));
    vector<tuple<char, int, int>> doors;
    deque<tuple<int, int>> dq;

    visited[0][0] = 1;
    dq.push_back({0, 0});

    while (!dq.empty()) {
      auto [now_y, now_x] = dq.front();
      dq.pop_front();

      for (int i = 0; i < 4; ++i) {
        int new_y = now_y + pattern_y[i];
        int new_x = now_x + pattern_x[i];

        if (new_y < 0 || new_y >= h + 2 || new_x < 0 || new_x >= w + 2) {
          continue;
        }

        if (visited[new_y][new_x]) {
          continue;
        }

        char& tile = v[new_y][new_x];

        if (tile == '*') {
          continue;
        }

        if (tile == '$') {
          tile = '@';
          ++result;
        } else if (tile >= 'a' && tile <= 'z') {
          keys.insert(tile);
          for (auto [door_char, door_x, door_y] : doors) {
            if (door_char == toupper(tile)) {
              dq.push_back({door_x, door_y});
            }
          }
        } else if (tile >= 'A' && tile <= 'Z') {
          if (keys.find(tolower(tile)) == keys.end()) {
            doors.push_back({tile, new_y, new_x});
            continue;
          }
        }

        visited[new_y][new_x] = 1;
        dq.push_back({new_y, new_x});
      }
    }

    cout << result << "\n";
  }

  return 0;
}