#include <bits/stdc++.h>
using namespace std;

void Union(vector<int>& points, int a, int b) {
  if (points[a] > points[b]) {
    swap(a, b);
  }

  points[a] += points[b];
  points[b] = a;
}

int Find(vector<int>& points, int x) {
  if (points[x] < 0) {
    return x;
  }

  return points[x] = Find(points, points[x]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> points(n + 1, -1);
  vector<tuple<int, int, int>> edges;
  edges.reserve(m);

  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    edges.emplace_back(a, b, c);
  }

  sort(edges.begin(), edges.end(),
       [](tuple<int, int, int>& left, tuple<int, int, int>& right) {
         return get<2>(left) < get<2>(right);
       });

  int result = 0;
  int max_cost = 0;
  int count = 0;

  for (auto [a, b, c] : edges) {
    a = Find(points, a);
    b = Find(points, b);

    if (a != b) {
      result += c;
      max_cost = max(max_cost, c);

      Union(points, a, b);

      if (++count == n - 1) {
        break;
      }
    }
  }

  cout << result - max_cost;

  return 0;
}