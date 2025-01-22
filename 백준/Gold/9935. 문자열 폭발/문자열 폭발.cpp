#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string str, bomb;
  cin >> str >> bomb;

  string result;
  result.reserve(str.size());
  char bomb_front = bomb.front();
  char bomb_back = bomb.back();
  int chain = 0;

  for (char c : str) {
    result.push_back(c);

    if (c == bomb_back && result.size() >= bomb.size()) {
      if (result[result.size() - bomb.size()] == bomb_front) {
        bool skip = false;

        for (int i = 1; i < bomb.size() - 1;) {
          if (result[result.size() - bomb.size() + i] != bomb[i]) {
            skip = true;
            break;
          }

          i += (bomb[i] == bomb_front ? chain : 1);
        }

        if (!skip) {
          result.resize(result.size() - bomb.size());
          chain = min(chain + 1, static_cast<int>(bomb.size()));
        }
      }

      chain = (c == bomb_front ? 1 : 0);
    }
  }

  cout << (result.empty() ? "FRULA" : result);

  return 0;
}