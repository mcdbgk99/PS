#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int k;
  cin >> k;

  for (int i = 0; i < k; ++i) {
    int n;
    cin >> n;
    if (n != 0) {
      v.push_back(n);
    } else {
      v.pop_back();
    }
  }

  cout << accumulate(v.begin(), v.end(), 0);

  return 0;
}