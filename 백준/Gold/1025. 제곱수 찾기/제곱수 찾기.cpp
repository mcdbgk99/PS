#include <bits/stdc++.h>
using namespace std;

vector<string> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  v.resize(n);

  for (int y = 0; y < n; ++y) {
    cin >> v[y];
  }

  int64_t result = -1;

  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      int64_t first_digit = v[y][x] - '0';
      if (pow(static_cast<int64_t>(sqrt(first_digit)), 2) == first_digit) {
        result = max(result, first_digit);
      }

      for (int add_y = 1 - n; add_y <= n - 1; ++add_y) {
        for (int add_x = 1 - m; add_x <= m - 1; ++add_x) {
          if (add_y == 0 && add_x == 0) {
            continue;
          }

          int64_t number = first_digit;
          int new_y = y + add_y;
          int new_x = x + add_x;

          while (new_y >= 0 && new_y < n && new_x >= 0 && new_x < m) {
            number = number * 10 + (v[new_y][new_x] - '0');
            if (pow(static_cast<int64_t>(sqrt(number)), 2) == number) {
              result = max(result, number);
            }

            new_y += add_y;
            new_x += add_x;
          }
        }
      }
    }
  }

  cout << result;

  return 0;
}