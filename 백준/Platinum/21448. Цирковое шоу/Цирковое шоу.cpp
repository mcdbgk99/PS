#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<tuple<i64, i64>> v(n);
  set<i64> temp;

  for (auto& [s, t] : v) {
    cin >> s >> t;
    temp.insert(s);
    temp.insert(s + t);
  }

  vector<i64> cut(temp.begin(), temp.end());
  int best = 0;
  i64 best_a, best_b = 0;

  for (i64 a : cut) {
    for (i64 b : cut) {
      if (a > b) {
        continue;
      }

      int left = 0, right = 0;

      for (auto& [s, t] : v) {
        if (s >= a && s + t <= b) {
          ++left;
        } else if (s >= b || s + t <= a) {
          ++right;
        }
      }

      int now = min(left, right);

      if (now > best) {
        best = now;
        best_a = a;
        best_b = b;
      }
    }
  }

  for (auto& [s, t] : v) {
    if (s >= best_a && s + t <= best_b) {
      cout << "1 ";
    } else if (s >= best_b || s + t <= best_a) {
      cout << "2 ";
    } else {
      cout << "0 ";
    }
  }

  return 0;
}