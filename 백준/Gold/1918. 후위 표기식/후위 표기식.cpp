#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string str;
  cin >> str;

  bool inside = false;
  string result;
  vector<char> oper;

  auto get_priority = [](char op) {
    if (op == '+' || op == '-') {
      return 1;
    } else if (op == '*' || op == '/') {
      return 2;
    } else {
      return 0;
    }
  };

  for (char c : str) {
    switch (c) {
      case '+':
      case '-':
      case '*':
      case '/': {
        while (!oper.empty() && get_priority(oper.back()) >= get_priority(c)) {
          result.push_back(oper.back());
          oper.pop_back();
        }
        oper.push_back(c);
      } break;

      case '(': {
        oper.push_back(c);
      } break;

      case ')': {
        while (!oper.empty() && oper.back() != '(') {
          result.push_back(oper.back());
          oper.pop_back();
        }
        oper.pop_back();
      } break;

      default: {
        result.push_back(c);
      } break;
    }
  }

  if (!oper.empty()) {
    for (int i = oper.size() - 1; i >= 0; --i) {
      result.push_back(oper[i]);
      oper.pop_back();
    }
  }

  cout << result;

  return 0;
}