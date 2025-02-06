#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
 private:
  int n;
  vector<int> tree;

 public:
  FenwickTree() {
    n = 0;
    tree.assign(1, 0);
  }

  FenwickTree(int n) : n(n), tree(n + 1, 0) {}

  void Update(int index, int delta) {
    for (; index <= n; index += index & -index) {
      tree[index] += delta;
    }
  }

  int Query(int index) {
    int sum = 0;
    for (; index > 0; index -= index & -index) {
      sum += tree[index];
    }
    return sum;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> a(k);

  for (int i = 0; i < k; ++i) {
    cin >> a[i];
  }

  int n_gate = n + 4;

  vector<int64_t> first_psum(k + 1, 0), last_psum(k + 1, 0);
  for (int i = 0; i < k; ++i) {
    first_psum[i + 1] = first_psum[i] + abs(a[i] - 1);
    last_psum[i + 1] = last_psum[i] + abs(a[i] - n);
  }

  vector<int64_t> mid(k, 0);
  for (int i = 0; i < k; ++i) {
    mid[i] = a[i] + 1 - i;
  }

  int64_t mid_cost = 0;
  for (int i = 3; i <= n; ++i) {
    mid_cost += abs(mid[i]);
  }

  FenwickTree fenwick;
  vector<int64_t> compressed;
  bool use_fenwick = (n > 3);

  if (use_fenwick) {
    int left = 4, right = k - 4;

    if (left <= right) {
      compressed.resize(right - left + 1);
      for (int i = left; i <= right; ++i) {
        compressed[i - left] = mid[i];
      }
      sort(compressed.begin(), compressed.end());
      compressed.erase(unique(compressed.begin(), compressed.end()),
                       compressed.end());
    }

    fenwick = FenwickTree(compressed.size());

    for (int i = 4; i <= n; ++i) {
      if (i < left || i > right) {
        continue;
      }
      int it = lower_bound(compressed.begin(), compressed.end(), mid[i]) -
               compressed.begin() + 1;
      fenwick.Update(it, 1);
    }
  }

  int64_t result = INT64_MAX;
  for (int i = 0; i <= k - n_gate; ++i) {
    int64_t first_cost = first_psum[i + 3] - first_psum[i];
    int64_t last_cost = last_psum[i + n + 4] - last_psum[i + n + 1];
    result = min(result, first_cost + mid_cost + last_cost);

    if (i == k - n_gate) {
      break;
    }

    int64_t delta = 0;
    if (use_fenwick) {
      int it;
      if (!compressed.empty()) {
        it = lower_bound(compressed.begin(), compressed.end(), -i) -
             compressed.begin() + 1;
      } else {
        it = 1;
      }
      int cnt = fenwick.Query(compressed.size()) - fenwick.Query(it - 1);
      delta = cnt * 2 - (n - 3);
    }

    if (use_fenwick) {
      int left = 4, right = k - 4;
      int last_add = i + n + 1, last_rem = i + 4;

      if (last_rem >= left && last_rem <= right) {
        int it =
            lower_bound(compressed.begin(), compressed.end(), mid[last_rem]) -
            compressed.begin() + 1;
        fenwick.Update(it, -1);
      }

      if (last_add >= left && last_add <= right) {
        int it =
            lower_bound(compressed.begin(), compressed.end(), mid[last_add]) -
            compressed.begin() + 1;
        fenwick.Update(it, 1);
      }
    }

    int64_t remove = abs(i + mid[i + 3]);
    int64_t add = abs((i + 1) + mid[i + n + 1]);
    mid_cost = mid_cost + delta - remove + add;
  }

  cout << result;

  return 0;
}