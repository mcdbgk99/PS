#include <bits/stdc++.h>
using namespace std;

constexpr int kMaxTaste = 1000000;

class FenwickTree {
 public:
  int n;
  vector<int> tree;

  FenwickTree(int n) : n(n), tree(n + 1, 0) {}

  void Update(int index, int delta) {
    for (; index <= n; index += index & -index) {
      tree[index] += delta;
    }
  }

  int FindTaste(int candy_index) {
    int result = 0, temp = 1 << 20;

    while (temp) {
      int taste = result + temp;

      if (taste <= n && tree[taste] < candy_index) {
        candy_index -= tree[taste];
        result = taste;
      }

      temp >>= 1;
    }

    return result + 1;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  FenwickTree fenwick(kMaxTaste);

  while (n--) {
    int type;
    cin >> type;

    if (type == 1) {
      int k;
      cin >> k;

      int taste = fenwick.FindTaste(k);
      cout << taste << "\n";
      fenwick.Update(taste, -1);
    } else if (type == 2) {
      int b, c;
      cin >> b >> c;

      fenwick.Update(b, c);
    }
  }

  return 0;
}