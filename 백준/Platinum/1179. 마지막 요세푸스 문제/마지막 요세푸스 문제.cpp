#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, k;
  cin >> n >> k;

  if (k == 1) {
    cout << n;
    return 0;
  }

  deque<tuple<int64_t, int64_t>> dq;

  while (n >= k) {
    dq.push_back({n, n % k});
    n -= n / k;
  }

  int64_t result = 0;
  for (int64_t i = 2; i <= n; ++i) {
    result = (result + k) % i;
  }

  while (!dq.empty()) {
    auto [s, r] = dq.back();
    dq.pop_back();

    result -= r;
    if (result < 0) {
      result += s;
    } else {
      result += result / (k - 1);
    }
  }

  cout << result + 1;

  return 0;
}