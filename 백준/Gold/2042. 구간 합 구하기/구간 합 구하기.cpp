#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
 private:
  int n;
  vector<int64_t> tree;

 public:
  FenwickTree() {
    n = 0;
    tree.assign(1, 0);
  }

  FenwickTree(int n) : n(n), tree(n + 1, 0) {}

  void Update(int index, int64_t delta) {
    for (; index <= n; index += index & -index) {
      tree[index] += delta;
    }
  }

  int64_t Query(int index) {
    int64_t sum = 0;
    for (; index > 0; index -= index & -index) {
      sum += tree[index];
    }
    return sum;
  }

  int64_t QueryRange(int left, int right) {
    return Query(right) - Query(left - 1);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  vector<int64_t> v(n + 1);
  FenwickTree fenwick(n);

  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
    fenwick.Update(i, v[i]);
  }

  int t = m + k;
  while (t--) {
    int64_t a, b, c;
    cin >> a >> b >> c;

    if (a == 1) {
      int64_t diff = c - v[b];
      v[b] = c;
      fenwick.Update(b, diff);
    } else if (a == 2) {
      cout << fenwick.QueryRange(b, c) << "\n";
    }
  }

  return 0;
}