#include <bits/stdc++.h>
using namespace std;

array<array<int8_t, 9>, 9> board;
array<array<bitset<9 + 1>, 9>, 3> mask;

bool Solve() {
  int empty_x = -1;
  int empty_y = -1;

  for (int y = 0; y < 9; ++y) {
    for (int x = 0; x < 9; ++x) {
      if (board[x][y] == 0) {
        empty_x = x;
        empty_y = y;
        break;
      }
    }

    if (empty_x != -1) {
      break;
    }
  }

  if (empty_x == -1) {
    return true;
  }

  for (int i = 1; i <= 9; ++i) {
    if (mask[0][empty_y][i] || mask[1][empty_x][i] ||
        mask[2][empty_x / 3 + empty_y / 3 * 3][i]) {
      continue;
    }

    board[empty_x][empty_y] = i;
    mask[0][empty_y][i] = 1;
    mask[1][empty_x][i] = 1;
    mask[2][empty_x / 3 + empty_y / 3 * 3][i] = 1;

    if (Solve()) {
      return true;
    }

    board[empty_x][empty_y] = 0;
    mask[0][empty_y][i] = 0;
    mask[1][empty_x][i] = 0;
    mask[2][empty_x / 3 + empty_y / 3 * 3][i] = 0;
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int y = 0; y < 9; ++y) {
    string str;
    cin >> str;

    for (int x = 0; x < 9; ++x) {
      board[x][y] = str[x] - '0';
      if (board[x][y] != 0) {
        mask[0][y][board[x][y]] = 1;
        mask[1][x][board[x][y]] = 1;
        mask[2][x / 3 + y / 3 * 3][board[x][y]] = 1;
      }
    }
  }

  Solve();

  for (int y = 0; y < 9; ++y) {
    for (int x = 0; x < 9; ++x) {
      cout << static_cast<int>(board[x][y]);
    }
    cout << "\n";
  }

  return 0;
}