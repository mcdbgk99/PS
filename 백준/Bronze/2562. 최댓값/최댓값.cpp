#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int best_index = 0;
  int best_num = 0;
  for (int i = 1; i <= 9; ++i) {
    int x;
    cin >> x;
    if (x > best_num) {
      best_num = x;
      best_index = i;
    }
  }

  cout << best_num << "\n" << best_index;

  return 0;
}