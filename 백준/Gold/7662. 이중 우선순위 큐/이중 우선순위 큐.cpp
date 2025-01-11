#include <bits/stdc++.h>
using namespace std;

map<int, int> m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int k;
    cin >> k;

    for (int j = 0; j < k; ++j) {
      char c;
      int n;
      cin >> c >> n;

      switch (c) {
        case 'I': {
          ++m[n];
        } break;

        case 'D': {
          if (m.empty()) {
            break;
          }

          if (n == -1) {
            int front = m.begin()->first;
            m.begin()->second -= 1;
            if (m.begin()->second <= 0) {
              m.erase(front);
            }
          } else {
            int back = m.rbegin()->first;
            m.rbegin()->second -= 1;
            if (m.rbegin()->second <= 0) {
              m.erase(back);
            }
          }
        } break;
      }
    }

    if (m.empty()) {
      cout << "EMPTY\n";
    } else {
      cout << m.rbegin()->first << " " << m.begin()->first << "\n";
    }

    m.clear();
  }

  return 0;
}