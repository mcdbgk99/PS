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
  int root = x;

  while (points[root] >= 0) {
    root = points[root];
  }

  while (root != x) {
    int next = points[x];
    points[x] = root;
    x = next;
  }

  return root;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int v, e;
  cin >> v >> e;

  vector<int> points(v + 1, -1);
  vector<array<int, 3>> edges;
  edges.reserve(e);

  for (int i = 0; i < e; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    edges.push_back({a, b, c});
  }

  sort(edges.begin(), edges.end(),
       [](array<int, 3>& left, array<int, 3>& right) {
         return left[2] < right[2];
       });

  int64_t result = 0;
  int count = 0;

  for (int i = 0; i < e; ++i) {
    auto [a, b, c] = edges[i];

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