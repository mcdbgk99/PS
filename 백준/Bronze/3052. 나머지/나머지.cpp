#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  unordered_set<int> s;

  for (int i = 0; i < 10; ++i) {
    int a;
    cin >> a;
    s.insert(a % 42);
  }

  cout << s.size();

  return 0;
}