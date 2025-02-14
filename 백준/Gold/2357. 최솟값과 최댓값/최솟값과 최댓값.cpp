#include <bits/stdc++.h>
using namespace std;

constexpr int kIntMax = 0x7FFFFFFF;
constexpr int kIntMin = 0x80000000;

class SegmentTree {
 public:
  int n;
  vector<array<int, 2>> tree;

  SegmentTree(int size) {
    n = 1;
    while (n < size) {
      n *= 2;
    }
    tree.assign(n * 2, {kIntMax, kIntMin});
  }

  void Update(int index, int delta) {
    index += n;
    tree[index] = {delta, delta};

    for (index /= 2; index >= 1; index /= 2) {
      tree[index][0] = min(tree[index * 2][0], tree[index * 2 + 1][0]);
      tree[index][1] = max(tree[index * 2][1], tree[index * 2 + 1][1]);
    }
  }

  array<int, 2> Query(int l, int r) {
    array<int, 2> result_l = {kIntMax, kIntMin};
    array<int, 2> result_r = {kIntMax, kIntMin};

    l += n;
    r += n;

    while (l < r) {
      if (l & 1) {
        result_l[0] = min(result_l[0], tree[l][0]);
        result_l[1] = max(result_l[1], tree[l][1]);
        ++l;
      }

      if (r & 1) {
        --r;
        result_r[0] = min(tree[r][0], result_r[0]);
        result_r[1] = max(tree[r][1], result_r[1]);
      }

      l /= 2;
      r /= 2;
    }

    return {min(result_l[0], result_r[0]), max(result_l[1], result_r[1])};
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  SegmentTree tree(n);

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    tree.Update(i, x);
  }

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    array<int, 2> result = tree.Query(a - 1, b);
    cout << result[0] << " " << result[1] << "\n";
  }

  return 0;
}