#include <bits/stdc++.h>
using namespace std;

vector<double> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  v.resize(n);
  double best = 0.0;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    best = max(best, v[i]);
  }
  for (int i = 0; i < n; ++i) {
    v[i] /= best;
    v[i] *= 100.0;
  }

  cout << setprecision(6);
  cout << accumulate(v.begin(), v.end(), 0.0) / v.size();

  return 0;
}