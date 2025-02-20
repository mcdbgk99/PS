#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

class FenwickTree {
 public:
  int n;
  vector<i64> tree, val;

  FenwickTree(int n) : n(n), tree(n + 1, 0), val(n, 0) {}

  void Update(int index, i64 delta) {
    val[index] += delta;
    ++index;

    for (; index <= n; index += index & -index) {
      tree[index] += delta;
    }
  }

  i64 Query(int index) {
    i64 result = 0;
    ++index;

    for (; index > 0; index -= index & -index) {
      result += tree[index];
    }

    return result;
  }

  int Search(i64 delta) {
    int result = 0;

    int i = 1;
    while (i <= n) {
      i <<= 1;
    }

    for (; i; i >>= 1) {
      int j = result + i;

      if (j <= n && tree[j] < delta) {
        delta -= tree[j];
        result = j;
      }
    }

    return result;
  }

  i64 Accumulate() { return Query(n - 1); }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    vector<int> a_unique = a;
    sort(a_unique.begin(), a_unique.end());
    a_unique.erase(unique(a_unique.begin(), a_unique.end()), a_unique.end());
    int a_unique_size = a_unique.size();

    vector<FenwickTree> trees;
    FenwickTree temp(a_unique_size);
    for (int i = 0; i < 5; ++i) {
      trees.push_back(temp);
    }

    vector<int> comp(n);
    for (int i = 0; i < n; ++i) {
      comp[i] = lower_bound(a_unique.begin(), a_unique.end(), a[i]) -
                a_unique.begin();
    }

    vector<i64> result(n, 0);
    i64 f = 0;
    vector<pair<int, i64>> now_state, new_state;

    for (int i = 0; i < n; ++i) {
      now_state.clear();
      now_state.push_back({comp[i], a[i]});

      for (int j = 0; j < 5; ++j) {
        new_state.clear();
        new_state.reserve(now_state.size());

        for (auto [key, delta] : now_state) {
          int index = key + 1;
          i64 original_delta = delta;

          while (delta > 0 && index < a_unique_size) {
            i64 sum = (index > 0 ? trees[j].Query(index - 1) : 0);

            if (!(trees[j].Accumulate() - sum)) {
              break;
            }

            int lower = trees[j].Search(sum + 1);
            i64 new_delta = min(delta, trees[j].val[lower]);
            trees[j].Update(lower, -new_delta);

            f -= new_delta;
            delta -= new_delta;
            new_state.push_back({lower, new_delta});
          }

          trees[j].Update(key, original_delta);
          f += original_delta;
        }

        swap(now_state, new_state);
      }

      result[i] = f;
    }

    for (int i = 0; i < n; ++i) {
      cout << result[i] << " ";
    }
    cout << "\n";
  }

  return 0;
}