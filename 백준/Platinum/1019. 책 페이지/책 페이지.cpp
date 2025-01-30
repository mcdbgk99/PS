#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  array<int, 10> result;
  result.fill(0);

  int power = 1;
  while (power <= n) {
    int left = n / power / 10;
    int mid = (n / power) % 10;
    int right = n % power;

    for (int i = 0; i < 10; ++i) {
      result[i] += left * power;

      if (i < mid) {
        result[i] += power;
      } else if (i == mid) {
        result[i] += right + 1;
      }
    }

    result[0] -= power;
    power *= 10;
  }

  for (int i : result) {
    cout << i << " ";
  }

  return 0;
}