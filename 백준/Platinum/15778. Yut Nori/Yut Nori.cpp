#include <bits/stdc++.h>
using namespace std;

const array<array<int, 5>, 30> kPath = {{
    {1, 2, 3, 4, 5},       // 날밭
    {2, 3, 4, 5, 6},       // 도
    {3, 4, 5, 6, 7},       // 개
    {4, 5, 6, 7, 8},       // 걸
    {5, 6, 7, 8, 9},       // 윷
    {20, 21, 22, 27, 28},  // 앞밭(모)
    {7, 8, 9, 10, 11},     // 뒷도
    {8, 9, 10, 11, 12},    // 뒷개
    {9, 10, 11, 12, 13},   // 뒷걸
    {10, 11, 12, 13, 14},  // 뒷윷
    {23, 24, 22, 25, 26},  // 뒷밭
    {12, 13, 14, 15, 16},  // 찌도
    {13, 14, 15, 16, 17},  // 찌개
    {14, 15, 16, 17, 18},  // 찌걸
    {15, 16, 17, 18, 19},  // 찌윷
    {16, 17, 18, 19, 29},  // 쩔밭
    {17, 18, 19, 29, -1},  // 날도
    {18, 19, 29, -1, -1},  // 날개
    {19, 29, -1, -1, -1},  // 날걸
    {29, -1, -1, -1, -1},  // 날윷
    {21, 22, 27, 28, 15},  // 앞모도
    {22, 27, 28, 15, 16},  // 앞모개
    {25, 26, 29, -1, -1},  // 방
    {24, 22, 25, 26, 29},  // 뒷모도
    {22, 25, 26, 29, -1},  // 뒷모개
    {26, 29, -1, -1, -1},  // 사려
    {29, -1, -1, -1, -1},  // 안찌
    {28, 15, 16, 17, 18},  // 속윷
    {15, 16, 17, 18, 19},  // 속모
    {-1, -1, -1, -1, -1},  // 날밭
}};

const array<int, 101> kCharToPlayer = [] {
  std::array<int, 101> arr = {};
  arr['A'] = 0;
  arr['B'] = 1;
  arr['C'] = 2;
  arr['D'] = 3;
  arr['a'] = 4;
  arr['b'] = 5;
  arr['c'] = 6;
  arr['d'] = 7;
  return arr;
}();
const array<int, 5> kOperToStep = {4, 0, 1, 2, 3};

const array<array<int, 2>, 30> kBoardPos = {{
    {30, 30},  // 날밭
    {24, 30},  // 도
    {18, 30},  // 개
    {12, 30},  // 걸
    {6, 30},   // 윷
    {0, 30},   // 앞밭(모)
    {0, 24},   // 뒷도
    {0, 18},   // 뒷개
    {0, 12},   // 뒷걸
    {0, 6},    // 뒷윷
    {0, 0},    // 뒷밭
    {6, 0},    // 찌도
    {12, 0},   // 찌개
    {18, 0},   // 찌걸
    {24, 0},   // 찌윷
    {30, 0},   // 쩔밭
    {30, 6},   // 날도
    {30, 12},  // 날개
    {30, 18},  // 날걸
    {30, 24},  // 날윷
    {5, 25},   // 앞모도
    {10, 20},  // 앞모개
    {15, 15},  // 방
    {5, 5},    // 뒷모도
    {10, 10},  // 뒷모개
    {20, 20},  // 사려
    {25, 25},  // 안찌
    {20, 10},  // 속윷
    {25, 5},   // 속모
    {30, 30},  // 날밭
}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<bitset<8>> board_to_player(30);
  vector<int> player_to_board(8, -1);

  auto print_board = [&board_to_player]() {
    vector<string> board_str = {
        R"(..----..----..----..----..----..)",
        R"(..    ..    ..    ..    ..    ..)",
        R"(| \                          / |)",
        R"(|  \                        /  |)",
        R"(|   \                      /   |)",
        R"(|    ..                  ..    |)",
        R"(..   ..                  ..   ..)",
        R"(..     \                /     ..)",
        R"(|       \              /       |)",
        R"(|        \            /        |)",
        R"(|         ..        ..         |)",
        R"(|         ..        ..         |)",
        R"(..          \      /          ..)",
        R"(..           \    /           ..)",
        R"(|             \  /             |)",
        R"(|              ..              |)",
        R"(|              ..              |)",
        R"(|             /  \             |)",
        R"(..           /    \           ..)",
        R"(..          /      \          ..)",
        R"(|         ..        ..         |)",
        R"(|         ..        ..         |)",
        R"(|        /            \        |)",
        R"(|       /              \       |)",
        R"(..     /                \     ..)",
        R"(..   ..                  ..   ..)",
        R"(|    ..                  ..    |)",
        R"(|   /                      \   |)",
        R"(|  /                        \  |)",
        R"(| /                          \ |)",
        R"(..    ..    ..    ..    ..    ..)",
        R"(..----..----..----..----..----..)",
    };

    for (int i = 0; i < 30; ++i) {
      for (int j = 0; j < 8; ++j) {
        if (board_to_player[i][j]) {
          int y = kBoardPos[i][0] + j % 4 / 2;
          int x = kBoardPos[i][1] + j % 4 % 2;

          board_str[y][x] = (j / 4 ? 'a' + j % 4 : 'A' + j % 4);
        }
      }
    }

    for (string str : board_str) {
      cout << str << "\n";
    }
  };

  auto move_player = [&board_to_player, &player_to_board](int player,
                                                          int step) {
    int team = player / 4;
    bitset<8> group;
    group[player] = 1;

    int now_pos = max(player_to_board[player], 0);
    for (int i = 0; i < 4; ++i) {
      if (board_to_player[now_pos][i + team * 4]) {
        board_to_player[now_pos][i + team * 4] = 0;
        group[i + team * 4] = 1;
      }
    }

    int new_pos = kPath[now_pos][step];
    for (int i = 0; i < 8; ++i) {
      if (!group[i]) {
        continue;
      }

      if (new_pos != -1) {
        board_to_player[new_pos][i] = 1;
      }
      player_to_board[i] = new_pos;
    }

    if (new_pos != -1) {
      int enemy_team = team ^ 1;
      for (int i = 0; i < 4; ++i) {
        if (board_to_player[new_pos][i + enemy_team * 4]) {
          board_to_player[new_pos][i + enemy_team * 4] = 0;
          player_to_board[i + enemy_team * 4] = -1;
        }
      }
    }
  };

  for (int i = 0; i < n; ++i) {
    char c;
    string str;
    cin >> c >> str;

    int player = kCharToPlayer[c];
    int step = 0;
    for (int j = 0; j < 4; ++j) {
      step += (str[j] == 'F');
    }
    step = kOperToStep[step];

    move_player(player, step);
  }

  print_board();

  return 0;
}