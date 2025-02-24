#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

struct Target {
  int score, index;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, n;
  cin >> a >> b >> n;

  vector<Target> vl, vr;

  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    vl.push_back({l, i});
    vr.push_back({r, i});
  }

  if (b > a) {
    cout << "-1 -1\n";
    return 0;
  }

  int best = INT32_MAX, x = -1, y = -1, len = a - b + 1;

  for (auto& t : vl) {
    if (t.score >= len && t.score < best) {
      best = t.score;
      x = t.index + 1;
      y = -1;
    }
  }

  for (auto& t : vr) {
    if (t.score >= len && t.score < best) {
      best = t.score;
      x = -1;
      y = t.index + 1;
    }
  }

  sort(vl.begin(), vl.end(),
       [](Target& left, Target& right) { return left.score < right.score; });
  sort(vr.begin(), vr.end(),
       [](Target& left, Target& right) { return left.score < right.score; });

  for (auto& l : vl) {
    int need = len - l.score;

    if (need <= 0) {
      break;
    }

    auto it = lower_bound(
        vr.begin(), vr.end(), Target{need, 0},
        [](Target left, Target right) { return left.score < right.score; });

    while (it != vr.end() && it->index == l.index) {
      ++it;
    }

    if (it != vr.end() && l.score + it->score < best) {
      best = l.score + it->score;
      x = l.index + 1;
      y = it->index + 1;
    }
  }

  if (best != INT32_MAX) {
    cout << x << " " << y;
  } else {
    cout << "No\n";
  }

  return 0;
}