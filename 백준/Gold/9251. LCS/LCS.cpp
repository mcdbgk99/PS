#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string a, b;
  cin >> a >> b;

  vector<int> temp(b.length() + 1, 0);
  v.push_back(temp);

  for (int i = 0; i < a.length(); ++i) {
    temp = v.back();
    for (int j = 0; j < b.length(); ++j) {
      if (a[i] == b[j]) {
        temp[j + 1] = v.back()[j] + 1;
      } else {
        temp[j + 1] = max(temp[j], v.back()[j + 1]);
      }
    }
    v.pop_back();
    v.push_back(temp);
  }

  int result = 0;
  for (int i : v.back()) {
    result = max(result, i);
  }

  cout << result;

  return 0;
}