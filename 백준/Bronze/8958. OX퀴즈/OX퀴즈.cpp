#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    string str;
    cin >> str;

    int result = 0;
    int streak = 0;
    for (char c : str) {
      if (c == 'O') {
        ++streak;
      } else {
        streak = 0;
      }

      result += streak;
    }

    cout << result << "\n";
  }

  return 0;
}