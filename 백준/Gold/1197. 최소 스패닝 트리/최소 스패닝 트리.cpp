#include <bits/stdc++.h>
using namespace std;

mt19937 gen(random_device{}());
uniform_int_distribution<int> dist(0, 1);

void Union(vector<int>& points, int a, int b) {
  if (dist(gen) == 0) {
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

  int v, e;
  cin >> v >> e;

  vector<int> points(v + 1, -1);
  vector<tuple<int, int16_t, int16_t>> edges;
  edges.reserve(e);

  for (int i = 0; i < e; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    edges.emplace_back(c, a, b);
  }

  sort(edges.begin(), edges.end(),
       [](tuple<int, int16_t, int16_t>& left,
          tuple<int, int16_t, int16_t>& right) {
         return get<0>(left) < get<0>(right);
       });

  int64_t result = 0;
  int count = 0;

  for (auto [c, a, b] : edges) {
    a = Find(points, a);
    b = Find(points, b);

    if (a != b) {
      result += c;

      Union(points, a, b);

      if (++count == v - 1) {
        break;
      }
    }
  }

  cout << result;

  return 0;
}