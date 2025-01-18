#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int64_t> v(6);

  int64_t n;
  cin >> n;

  for (int i = 0; i < 6; ++i) {
    cin >> v[i];
  }

  if (n == 1) {
    cout << accumulate(v.begin(), v.end(), 0) -
                max({v[0], v[1], v[2], v[3], v[4], v[5]});
  } else {
    vector<int64_t> dice_min = {
        min({v[0], v[1], v[2], v[3], v[4], v[5]}),
        min({v[0] + v[1], v[0] + v[2], v[0] + v[3], v[0] + v[4], v[1] + v[2],
             v[1] + v[3], v[1] + v[5], v[2] + v[4], v[2] + v[5], v[3] + v[4],
             v[3] + v[5], v[4] + v[5]}),
        min({v[0] + v[1] + v[2], v[0] + v[1] + v[3], v[0] + v[2] + v[4],
             v[0] + v[3] + v[4], v[1] + v[2] + v[5], v[1] + v[3] + v[5],
             v[2] + v[4] + v[5], v[3] + v[4] + v[5]})};

    cout << dice_min[2] * 4 + dice_min[1] * ((n - 2) * 8 + 4) +
                dice_min[0] * ((n - 2) * (n - 2) * 5 + (n - 2) * 4);
  }

  return 0;
}