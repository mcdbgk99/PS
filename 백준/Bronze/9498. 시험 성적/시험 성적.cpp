#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t score;
  cin >> score;
  cout << (score < 60 ? 'F'
                      : "DCBA"[(((score - 60) * 0xCCCCCCCD) >> 35) > 3
                                   ? 3
                                   : (((score - 60) * 0xCCCCCCCD) >> 35)]);
  return 0;
}