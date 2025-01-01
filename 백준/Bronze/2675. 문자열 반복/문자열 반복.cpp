#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int x;
    cin >> x;
    string str;
    cin >> str;

    for (char c : str) {
      for (int i = 0; i < x; ++i) {
        cout << c;
      }
    }

    cout << "\n";
  }

  return 0;
}