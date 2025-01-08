#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> temp;
unordered_map<int, int> m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  v.resize(n);
  temp.resize(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    temp[i] = v[i];
  }

  sort(temp.begin(), temp.end());
  temp.erase(unique(temp.begin(), temp.end()), temp.end());

  for (int i = 0; i < temp.size(); ++i) {
    m.insert({temp[i], i});
  }

  for (int i = 0; i < n; ++i) {
    cout << m[v[i]] << " ";
  }

  return 0;
}