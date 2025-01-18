#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> party_to_human;
vector<vector<int>> human_to_party;
vector<bool> visited;
queue<int> q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, truth_count;
  cin >> n >> m >> truth_count;

  party_to_human.resize(m);
  human_to_party.resize(n + 1);
  visited.resize(m, false);

  for (int i = 0; i < truth_count; ++i) {
    int x;
    cin >> x;
    q.push(x);
  }

  for (int i = 0; i < m; ++i) {
    int all_count;
    cin >> all_count;

    for (int j = 0; j < all_count; ++j) {
      int x;
      cin >> x;
      party_to_human[i].push_back(x);
      human_to_party[x].push_back(i);
    }
  }

  while (!q.empty()) {
    int now = q.front();
    q.pop();

    for (int i : human_to_party[now]) {
      if (visited[i]) {
        continue;
      }

      visited[i] = true;

      for (int j : party_to_human[i]) {
        q.push(j);
      }
    }
  }

  int result = 0;
  for (bool b : visited) {
    if (!b) {
      ++result;
    }
  }

  cout << result;

  return 0;
}