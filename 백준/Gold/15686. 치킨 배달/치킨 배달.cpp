#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int>> house;
vector<tuple<int, int>> chicken;
set<vector<int>> s;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      int a;
      cin >> a;

      if (a == 1) {
        house.push_back({x, y});
      } else if (a == 2) {
        chicken.push_back({x, y});
      }
    }
  }

  vector<int> chicken_indexes(chicken.size(), 0);
  fill(chicken_indexes.end() - m, chicken_indexes.end(), 1);

  do {
    vector<int> temp;
    for (int i = 0; i < chicken_indexes.size(); ++i) {
      if (chicken_indexes[i] == 1) {
        temp.push_back(i);
      }
    }
    s.insert(temp);
  } while (next_permutation(chicken_indexes.begin(), chicken_indexes.end()));

  int result = INT32_MAX;

  for (auto& v : s) {
    int sum = 0;
    for (auto& [house_x, house_y] : house) {
      int dist = INT32_MAX;
      for (int i : v) {
        auto [chicken_x, chicken_y] = chicken[i];
        dist = min(dist, abs(house_x - chicken_x) + abs(house_y - chicken_y));
      }
      sum += dist;
    }
    result = min(result, sum);
  }

  cout << result;

  return 0;
}