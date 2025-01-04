#include <bits/stdc++.h>
using namespace std;

unordered_map<int, string> num_to_str;
unordered_map<string, int> str_to_num;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    string str;
    cin >> str;
    num_to_str.insert({i + 1, str});
    str_to_num.insert({str, i + 1});
  }

  for (int i = 0; i < m; ++i) {
    string str;
    cin >> str;

    bool is_number = true;
    for (char c : str) {
      if (!isdigit(c)) {
        is_number = false;
        break;
      }
    }

    if (is_number) {
      cout << num_to_str[stoi(str)] << "\n";
    } else {
      cout << str_to_num[str] << "\n";
    }
  }

  return 0;
}