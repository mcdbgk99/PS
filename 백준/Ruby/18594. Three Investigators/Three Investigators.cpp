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

    for (int i = 1 << 20; i; i >>= 1) {
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

    vector<FenwickTree> trees;

    for (int i = 0; i <= 5; ++i) {
      trees.push_back(FenwickTree(a_unique.size()));
    }

    vector<i64> result(n, 0);
    i64 final = 0;

    for (int i = 0; i < n; ++i) {
      vector<pair<int, i64>> now_state;
      now_state.push_back({a[i], a[i]});

      for (int j = 0; j < 5; ++j) {
        vector<pair<int, i64>> new_state;

        for (auto [key, delta] : now_state) {
          int index = upper_bound(a_unique.begin(), a_unique.end(), key) -
                      a_unique.begin();
          i64 original_delta = delta;

          while (delta > 0 && index < a_unique.size()) {
            i64 sum = (index > 0 ? trees[j].Query(index - 1) : 0);

            if (!(trees[j].Accumulate() - sum)) {
              break;
            }

            int lower = trees[j].Search(sum + 1);
            i64 new_delta = min(delta, trees[j].val[lower]);
            trees[j].Update(lower, -new_delta);

            final -= new_delta;
            delta -= new_delta;
            new_state.push_back({a_unique[lower], new_delta});
          }

          int lower = lower_bound(a_unique.begin(), a_unique.end(), key) -
                      a_unique.begin();
          trees[j].Update(lower, original_delta);
          final += original_delta;
        }

        now_state = move(new_state);
      }

      result[i] = final;
    }

    for (int i = 0; i < n; ++i) {
      cout << result[i] << " ";
    }
    cout << "\n";
  }

  return 0;
}