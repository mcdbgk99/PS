#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  string str;
  cin >> str;

  int result = 0;
  for (char c : str) {
    result += c - '0';
  }

  cout << result;

  return 0;
}