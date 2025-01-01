#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> asc(8);
  iota(asc.begin(), asc.end(), 1);
  vector<int> des(8);
  iota(des.begin(), des.end(), 1);
  reverse(des.begin(), des.end());

  int asc_count = 0;
  int des_count = 0;

  for (int i = 0; i < 8; ++i) {
    int x;
    cin >> x;
    if (asc[i] == x) {
      ++asc_count;
    } else if (des[i] == x) {
      ++des_count;
    }
  }

  if (asc_count == 8) {
    cout << "ascending";
  } else if (des_count == 8) {
    cout << "descending";
  } else {
    cout << "mixed";
  }

  return 0;
}