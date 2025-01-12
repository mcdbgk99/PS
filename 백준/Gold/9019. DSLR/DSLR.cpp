#include <bits/stdc++.h>
using namespace std;

vector<tuple<bool, int, char>> visited;
deque<int> dq;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int a, b;
    cin >> a >> b;

    visited.assign(10000, {false, -1, 0});
    visited[a] = {true, -1, 0};
    dq.push_back(a);

    while (!dq.empty()) {
      int now_num = dq.front();
      dq.pop_front();

      if (now_num == b) {
        break;
      }

      int d_num = now_num * 2 % 10000;
      if (!get<0>(visited[d_num])) {
        visited[d_num] = {true, now_num, 'D'};
        dq.push_back(d_num);
      }

      int s_num = (now_num != 0 ? now_num - 1 : 9999);
      if (!get<0>(visited[s_num])) {
        visited[s_num] = {true, now_num, 'S'};
        dq.push_back(s_num);
      }

      int l_num = (now_num % 1000) * 10 + now_num / 1000;
      if (!get<0>(visited[l_num])) {
        visited[l_num] = {true, now_num, 'L'};
        dq.push_back(l_num);
      }

      int r_num = (now_num % 10) * 1000 + now_num / 10;
      if (!get<0>(visited[r_num])) {
        visited[r_num] = {true, now_num, 'R'};
        dq.push_back(r_num);
      }
    }

    dq.clear();

    deque<char> result;
    int index = b;
    while (index != a) {
      result.push_front(get<2>(visited[index]));
      index = get<1>(visited[index]);
    }

    for (char c : result) {
      cout << c;
    }

    cout << "\n";
  }

  return 0;
}