#include <bits/stdc++.h>
using namespace std;

string str;
vector<int> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m >> str;

  size_t index = 0;
  int count = 0;
  while (index < str.size()) {
    if (index < str.size() - 1 && str[index] == 'I' && str[index + 1] == 'O') {
      ++count;
      index += 2;
      continue;
    }

    if (count > 0) {
      v.push_back(count + (str[index] == 'I' ? 0 : -1));
      count = 0;
    }

    ++index;
  }

  if (count > 0) {
    v.push_back(count + (str[index] == 'I' ? 0 : -1));
  }

  int result = 0;

  for (int i : v) {
    if (i >= n) {
      result += i - n + 1;
    }
  }

  cout << result;

  return 0;
}