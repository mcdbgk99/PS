#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> v(6);
  for (int i = 0; i < v.size(); ++i) {
    cin >> v[i];
  }

  int t, p;
  cin >> t >> p;

  vector<int> result(3);
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] == 0) {
      continue;
    }

    result[0] += (v[i] - 1) / t + 1;
  }

  result[1] = n / p;
  result[2] = n % p;

  cout << result[0] << "\n" << result[1] << " " << result[2];

  return 0;
}