#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string str, bomb;
  cin >> str >> bomb;

  string result;
  vector<int> match;

  for (char c : str) {
    result.push_back(c);
    int current = 0;

    if (match.empty()) {
      if (c == bomb[0]) {
        current = 1;
      }
    } else {
      int prev = match.back();
      if (prev < bomb.length() && c == bomb[prev]) {
        current = prev + 1;
      }
    }

    if (current == 0 && c == bomb[0]) {
      current = 1;
    }

    match.push_back(current);

    if (current == bomb.length()) {
      result.erase(result.end() - bomb.length(), result.end());
      match.erase(match.end() - bomb.length(), match.end());
    }
  }

  cout << (result.empty() ? "FRULA" : result);

  return 0;
}