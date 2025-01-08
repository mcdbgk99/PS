#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> compress;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  v.resize(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  compress = v;

  sort(compress.begin(), compress.end());
  compress.erase(unique(compress.begin(), compress.end()), compress.end());

  for (int i = 0; i < n; ++i) {
    cout << lower_bound(compress.begin(), compress.end(), v[i]) -
                compress.begin()
         << " ";
  }

  return 0;
}