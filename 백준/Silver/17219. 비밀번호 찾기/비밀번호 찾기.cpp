#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  unordered_map<string, string> passwords;
  passwords.reserve(n);

  for (int i = 0; i < n; ++i) {
    string url, password;
    cin >> url >> password;
    passwords.insert({url, password});
  }

  for (int i = 0; i < m; ++i) {
    string url;
    cin >> url;
    cout << passwords[url] << "\n";
  }

  return 0;
}