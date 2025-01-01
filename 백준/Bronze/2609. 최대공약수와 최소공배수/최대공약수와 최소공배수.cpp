#include <bits/stdc++.h>
using namespace std;

vector<int> v(2);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> v[0] >> v[1];
  sort(v.begin(), v.end());
  int div = gcd(v[0], v[1]);
  int mul = v[1] / div * v[0];
  cout << div << "\n" << mul;

  return 0;
}