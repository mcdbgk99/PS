#include <bits/stdc++.h>
using namespace std;

vector<string> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  v.resize(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  sort(v.begin(), v.end(), [](string& left, string& right) {
    return left.length() < right.length() ||
           (left.length() == right.length() ? left < right : false);
  });

  v.erase(unique(v.begin(), v.end()), v.end());

  for (string str : v) {
    cout << str << "\n";
  }

  return 0;
}