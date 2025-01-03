#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  v.resize(n);
  iota(v.begin(), v.end(), 1);

  cout << "<";

  size_t index = 0;
  while (!v.empty()) {
    index += k - 1;
    index %= v.size();

    cout << v[index];
    if (v.size() > 1) {
      cout << ", ";
    }
    v.erase(v.begin() + index);
  }

  cout << ">";

  return 0;
}