#include <bits/stdc++.h>
using namespace std;

auto cmp = [](int left, int right) {
  return abs(left) > abs(right) ||
         (abs(left) == abs(right) ? left > right : false);
};
priority_queue<int, vector<int>, decltype(cmp)> pq;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x != 0) {
      pq.push(x);
    } else {
      if (pq.empty()) {
        cout << "0\n";
      } else {
        cout << pq.top() << "\n";
        pq.pop();
      }
    }
  }

  return 0;
}