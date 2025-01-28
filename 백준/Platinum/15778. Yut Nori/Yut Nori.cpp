#include <bits/stdc++.h>
using namespace std;

const vector<array<int, 5>> kPath = {
    {1, 2, 3, 4, 5},      {2, 3, 4, 5, 6},      {3, 4, 5, 6, 7},
    {4, 5, 6, 7, 8},      {5, 6, 7, 8, 9},      {20, 21, 22, 27, 28},
    {7, 8, 9, 10, 11},    {8, 9, 10, 11, 12},   {9, 10, 11, 12, 13},
    {10, 11, 12, 13, 14}, {23, 24, 22, 25, 26}, {12, 13, 14, 15, 16},
    {13, 14, 15, 16, 17}, {14, 15, 16, 17, 18}, {15, 16, 17, 18, 19},
    {16, 17, 18, 19, 29}, {17, 18, 19, 29, -1}, {18, 19, 29, -1, -1},
    {19, 29, -1, -1, -1}, {29, -1, -1, -1, -1}, {21, 22, 27, 28, 15},
    {22, 27, 28, 15, 16}, {25, 26, 29, -1, -1}, {24, 22, 25, 26, 29},
    {22, 25, 26, 29, -1}, {26, 29, -1, -1, -1}, {29, -1, -1, -1, -1},
    {28, 15, 16, 17, 18}, {15, 16, 17, 18, 19}, {-1, -1, -1, -1, -1},
};

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

const vector<array<int, 2>> kBoardPos = {
    {30, 30}, {24, 30}, {18, 30}, {12, 30}, {6, 30},  {0, 30},
    {0, 24},  {0, 18},  {0, 12},  {0, 6},   {0, 0},   {6, 0},
    {12, 0},  {18, 0},  {24, 0},  {30, 0},  {30, 6},  {30, 12},
    {30, 18}, {30, 24}, {5, 25},  {10, 20}, {15, 15}, {5, 5},
    {10, 10}, {20, 20}, {25, 25}, {20, 10}, {25, 5},  {30, 30},
};

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

  auto move_player = [&print_board, &board_to_player, &player_to_board](
                         int player, int step) {
    int team = player / 4;
    set<int> group = {player};

    int now_pos = max(player_to_board[player], 0);
    for (int i = 0; i < 4; ++i) {
      if (board_to_player[now_pos][i + team * 4]) {
        board_to_player[now_pos][i + team * 4] = 0;
        group.insert(i + team * 4);
      }
    }

    int new_pos = kPath[now_pos][step];
    for (int i : group) {
      if (new_pos != -1) {
        board_to_player[new_pos][i] = 1;
      }
      player_to_board[i] = new_pos;
    }

    if (new_pos != -1) {
      for (int i = 0; i < 4; ++i) {
        if (board_to_player[new_pos][i + (team ^ 1) * 4]) {
          board_to_player[new_pos][i + (team ^ 1) * 4] = 0;
          player_to_board[i + (team ^ 1) * 4] = -1;
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