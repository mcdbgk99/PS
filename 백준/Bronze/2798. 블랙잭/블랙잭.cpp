#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  v.resize(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  int result = 0;
  for (int i = 0; i < v.size(); ++i) {
    for (int j = i + 1; j < v.size(); ++j) {
      for (int k = j + 1; k < v.size(); ++k) {
        if (v[i] + v[j] + v[k] > m) {
          break;
        }

        result = max(result, v[i] + v[j] + v[k]);
      }
    }
  }

  cout << result;

  return 0;
}