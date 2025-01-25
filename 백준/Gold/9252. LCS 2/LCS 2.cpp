#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string a, b;
  cin >> a >> b;

  vector<vector<int>> v;
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
    v.push_back(temp);
  }

  int lcs_length = v.back().back();
  int lcs_index = v.back().size() - 1;
  cout << lcs_length << "\n";
  if (lcs_length == 0) {
    return 0;
  }

  vector<char> result;

  int i = a.length();
  int j = b.length();
  while (i > 0 && j > 0) {
    if (a[i - 1] == b[j - 1]) {
      result.push_back(a[i - 1]);
      --i;
      --j;
    } else if (v[i][j] == v[i - 1][j]) {
      --i;
    } else {
      --j;
    }
  }

  auto it = result.rbegin();
  while (it != result.rend()) {
    cout << *it;
    ++it;
  }

  return 0;
}