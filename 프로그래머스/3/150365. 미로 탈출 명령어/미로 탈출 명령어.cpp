#include <queue>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

// n, m: board_size
// x, y: start_pos
// r, c: end_pos
// k: dist
string solution(int n, int m, int x, int y, int r, int c, int k) {
  string answer = "";

  vector<tuple<char, int, int>> patterns = {
      {'d', 1, 0}, {'l', 0, -1}, {'r', 0, 1}, {'u', -1, 0}};

  vector<vector<vector<char>>> v(
      n + 1, vector<vector<char>>(m + 1, vector<char>(k + 1, 0)));
  deque<tuple<int, int, int, string>> dq;

  dq.push_back({x, y, 0, ""});

  while (!dq.empty()) {
    auto [now_x, now_y, step, result] = dq.front();
    dq.pop_front();

    if (step == k) {
      if (now_x == r && now_y == c) {
        return result;
      }
      continue;
    }

    for (auto& pattern : patterns) {
      int new_x = now_x + get<1>(pattern);
      int new_y = now_y + get<2>(pattern);

      if (new_x < 1 || new_x > n || new_y < 1 || new_y > m) {
        continue;
      }

      if (v[new_x][new_y][step + 1]) {
        continue;
      }

      v[new_x][new_y][step + 1] = 1;
      dq.push_back({new_x, new_y, step + 1, result + get<0>(pattern)});
    }
  }

  return "impossible";
}