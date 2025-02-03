#include <bits/stdc++.h>
using namespace std;

inline void Union(vector<int> &nodes, int a, int b) {
  if (nodes[a] > nodes[b]) {
    swap(a, b);
  }

  nodes[a] += nodes[b];
  nodes[b] = a;
}

inline int Find(vector<int> &nodes, int x) {
  while (nodes[x] >= 0) {
    int p = nodes[x];
    if (nodes[p] >= 0) {
      nodes[x] = nodes[p];
    }
    x = p;
  }
  return x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<array<int, 4>> planet(n);

  for (int i = 0; i < n; ++i) {
    cin >> planet[i][0] >> planet[i][1] >> planet[i][2];
    planet[i][3] = i;
  }

  vector<array<int, 3>> edges;
  for (int i = 0; i < 3; i++) {
    sort(planet.begin(), planet.end(),
         [i](array<int, 4> &left, array<int, 4> &right) {
           return left[i] < right[i];
         });

    for (int j = 1; j < n; j++) {
      edges.push_back({abs(planet[j][i] - planet[j - 1][i]), planet[j - 1][3],
                       planet[j][3]});
    }
  }

  sort(edges.begin(), edges.end(),
       [](array<int, 3> &left, array<int, 3> &right) {
         return left[0] < right[0];
       });

  vector<int> nodes(n, -1);
  int64_t result = 0;
  int count = 0;

  for (auto [cost, u, v] : edges) {
    u = Find(nodes, u);
    v = Find(nodes, v);

    if (u != v) {
      result += cost;
      Union(nodes, u, v);
      if (++count == n - 1) {
        break;
      }
    }
  }

  cout << result;

  return 0;
}