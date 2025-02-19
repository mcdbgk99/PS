#include <bits/stdc++.h>
using namespace std;

struct File {
  string name;
  string extension;
  bool known;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<File> v;
  v.reserve(n);

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    size_t pos = s.find('.');
    v.push_back({s.substr(0, pos), s.substr(pos + 1), false});
  }

  unordered_set<string> known;

  for (int i = 0; i < m; ++i) {
    string s;
    cin >> s;
    known.insert(s);
  }

  for (auto &f : v) {
    if (known.find(f.extension) != known.end()) {
      f.known = true;
    }
  }

  sort(v.begin(), v.end(), [](File &left, File &right) {
    if (left.name != right.name) {
      return left.name < right.name;
    }

    if (left.known != right.known) {
      return left.known > right.known;
    }

    return left.extension < right.extension;
  });

  for (auto &f : v) {
    cout << f.name << "." << f.extension << "\n";
  }

  return 0;
}