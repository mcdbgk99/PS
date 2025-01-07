#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  v.resize(sqrt(n) + 1);
  for (int i = 1; i < v.size(); ++i) {
    v[i] = i * i;
  }

  int result = 4;

  for (int i = 1; i < v.size(); ++i) {
    if (v[i] >= n) {
      if (v[i] == n) {
        result = min(result, 1);
      }
      break;
    }

    for (int j = 1; j < v.size(); ++j) {
      if (v[i] + v[j] >= n) {
        if (v[i] + v[j] == n) {
          result = min(result, 2);
        }
        break;
      }

      for (int k = 1; k < v.size(); ++k) {
        if (v[i] + v[j] + v[k] >= n) {
          if (v[i] + v[j] + v[k] == n) {
            result = min(result, 3);
          }
          break;
        }
      }
    }
  }

  cout << result;

  return 0;
}