#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int result = 0;

  for (int i = 0; i < 3; ++i) {
    string str;
    cin >> str;
    bool pass = false;
    for (char c : str) {
      if (isalpha(c)) {
        pass = true;
        break;
      }
    }

    if (!pass) {
      result = stoi(str) + (3 - i);
    }
  }

  bool three = (result % 3 == 0);
  bool five = (result % 5 == 0);
  if (three && five) {
    cout << "FizzBuzz";
  } else if (three && !five) {
    cout << "Fizz";
  } else if (!three && five) {
    cout << "Buzz";
  } else {
    cout << result;
  }

  return 0;
}