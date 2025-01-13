#include <bits/stdc++.h>
using namespace std;

vector<int> v;
set<vector<int>> s;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  v.resize(n);
  iota(v.begin(), v.end(), 1);

  do {
    vector<int> temp(v.begin(), v.begin() + m);
    sort(temp.begin(), temp.end());

    if (s.insert(temp).second) {
      for (int i : temp) {
        cout << i << " ";
      }
      cout << "\n";
    }
  } while (next_permutation(v.begin(), v.end()));

  return 0;
}