#include <bits/stdc++.h>
using namespace std;

vector<int> v;
stack<int> s;
vector<bool> result;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  v.resize(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  int v_index = 0;
  int x = 1;
  while (v_index < v.size()) {
    if (!s.empty() && s.top() == v[v_index]) {
      result.push_back(false);
      s.pop();
      ++v_index;
      continue;
    }

    if (x <= v[v_index]) {
      result.push_back(true);
      s.push(x);
      ++x;
      continue;
    }

    break;
  }

  if (v_index != v.size() || x - 1 != n) {
    cout << "NO";
  } else {
    for (int i = 0; i < result.size(); ++i) {
      cout << (result[i] ? "+" : "-") << "\n";
    }
  }

  return 0;
}