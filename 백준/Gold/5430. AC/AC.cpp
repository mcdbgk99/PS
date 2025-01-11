#include <bits/stdc++.h>
using namespace std;

deque<int> dq;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    string command;
    cin >> command;
    int n;
    cin >> n;
    string arr_str;
    cin >> arr_str;

    int index = 0;
    string num_str;

    while (index < arr_str.size()) {
      if (arr_str[index] == '[' || arr_str[index] == ']' ||
          arr_str[index] == ',') {
        if (!num_str.empty()) {
          dq.push_back(stoi(num_str));
          num_str.clear();
        }

        ++index;
        continue;
      }

      num_str += (arr_str[index]);
      ++index;
    }

    bool error = false;
    bool reversed = false;

    for (char c : command) {
      if (error) {
        break;
      }

      switch (c) {
        case 'R': {
          reversed = !reversed;
        } break;

        case 'D': {
          if (!dq.empty()) {
            if (reversed) {
              dq.pop_back();
            } else {
              dq.pop_front();
            }
          } else {
            error = true;
          }
        } break;
      }
    }

    if (error) {
      cout << "error\n";
    } else {
      cout << "[";
      if (reversed) {
        for (int j = dq.size() - 1; j >= 0; --j) {
          cout << dq[j];
          if (j != 0) {
            cout << ",";
          }
        }
      } else {
        for (int j = 0; j < dq.size(); ++j) {
          cout << dq[j];
          if (j != dq.size() - 1) {
            cout << ",";
          }
        }
      }
      cout << "]\n";
    }

    dq.clear();
  }

  return 0;
}