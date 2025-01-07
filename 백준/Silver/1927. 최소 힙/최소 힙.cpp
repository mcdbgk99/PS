#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<>> pq;

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
      if (!pq.empty()) {
        cout << pq.top() << "\n";
        pq.pop();
      } else {
        cout << "0\n";
      }
    }
  }

  return 0;
}