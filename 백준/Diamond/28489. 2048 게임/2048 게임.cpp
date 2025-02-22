#include <bits/stdc++.h>
using namespace std;
using Board = vector<vector<int>>;

constexpr int kBoard = 4, kMaxDepth = 4;
constexpr array<double, 16> kWeight = {
    65536, 32768, 16384, 8192, 4096, 2048, 1024, 512,
    256,   128,   64,    32,   16,   8,    4,    2,
};

const vector<pair<int, int>> order = {
    {0, 0}, {0, 1}, {0, 2}, {0, 3}, {1, 3}, {1, 2}, {1, 1}, {1, 0},
    {2, 0}, {2, 1}, {2, 2}, {2, 3}, {3, 3}, {3, 2}, {3, 1}, {3, 0}};

bool Equal(const Board &a, const Board &b) {
  for (int i = 0; i < kBoard; ++i) {
    for (int j = 0; j < kBoard; ++j) {
      if (a[i][j] != b[i][j]) {
        return false;
      }
    }
  }

  return true;
}

Board Left(const Board &board) {
  Board result = board;

  for (int i = 0; i < kBoard; ++i) {
    vector<int> r;

    for (int j = 0; j < kBoard; ++j) {
      if (result[i][j] != 0) {
        r.push_back(result[i][j]);
      }
    }

    vector<int> m;

    for (int j = 0; j < r.size(); ++j) {
      if (j + 1 < r.size() && r[j] == r[j + 1]) {
        m.push_back(r[j] * 2);
        ++j;
      } else {
        m.push_back(r[j]);
      }
    }

    while (m.size() < kBoard) {
      m.push_back(0);
    }

    result[i] = m;
  }

  return result;
}

Board Right(const Board &board) {
  Board result = board;

  for (int i = 0; i < kBoard; ++i) {
    vector<int> r;

    for (int j = kBoard - 1; j >= 0; --j) {
      if (result[i][j] != 0) {
        r.push_back(result[i][j]);
      }
    }

    vector<int> m;

    for (int j = 0; j < r.size(); ++j) {
      if (j + 1 < r.size() && r[j] == r[j + 1]) {
        m.push_back(r[j] * 2);
        ++j;
      } else {
        m.push_back(r[j]);
      }
    }

    while (m.size() < kBoard) {
      m.push_back(0);
    }

    reverse(m.begin(), m.end());

    result[i] = m;
  }

  return result;
}

Board Up(const Board &board) {
  Board result = board;

  for (int j = 0; j < kBoard; ++j) {
    vector<int> c;

    for (int i = 0; i < kBoard; ++i) {
      if (result[i][j] != 0) {
        c.push_back(result[i][j]);
      }
    }

    vector<int> m;

    for (int i = 0; i < c.size(); ++i) {
      if (i + 1 < c.size() && c[i] == c[i + 1]) {
        m.push_back(c[i] * 2);
        ++i;
      } else {
        m.push_back(c[i]);
      }
    }

    while (m.size() < kBoard) {
      m.push_back(0);
    }

    for (int i = 0; i < kBoard; ++i) {
      result[i][j] = m[i];
    }
  }

  return result;
}

Board Down(const Board &board) {
  Board result = board;

  for (int j = 0; j < kBoard; ++j) {
    vector<int> c;

    for (int i = kBoard - 1; i >= 0; --i) {
      if (result[i][j] != 0) {
        c.push_back(result[i][j]);
      }
    }

    vector<int> m;

    for (int i = 0; i < c.size(); ++i) {
      if (i + 1 < c.size() && c[i] == c[i + 1]) {
        m.push_back(c[i] * 2);
        ++i;
      } else {
        m.push_back(c[i]);
      }
    }

    while (m.size() < kBoard) {
      m.push_back(0);
    }

    reverse(m.begin(), m.end());

    for (int i = 0; i < kBoard; ++i) {
      result[i][j] = m[i];
    }
  }

  return result;
}

double Eval(const Board &board) {
  double score = 0.0, penalty = 0.0;
  int free = 0, best = 0;

  for (int x = 0; x < order.size(); x++) {
    int i = order[x].first, j = order[x].second;
    int tile = board[i][j];

    if (tile == 0) {
      ++free;
    } else {
      best = max(best, tile);
      score += log2(tile) * kWeight[x];
    }
  }

  for (int x = 0; x < order.size() - 1; ++x) {
    int i1 = order[x].first, j1 = order[x].second;
    int i2 = order[x + 1].first, j2 = order[x + 1].second;
    int tile1 = board[i1][j1], tile2 = board[i2][j2];

    if (tile1 < tile2) {
      penalty += (tile2 - tile1) * 100;
    }
  }

  score += free * 1000;
  score += best * 1000;

  return score - penalty;
}

double Expectimax(const Board &board, int depth, bool turn) {
  if (depth == 0) {
    return Eval(board);
  }

  if (turn) {
    double best = -1e9;
    vector<pair<string, Board>> moves = {{"LEFT", Left(board)},
                                         {"UP", Up(board)},
                                         {"RIGHT", Right(board)},
                                         {"DOWN", Down(board)}};
    bool moved = false;

    for (auto &p : moves) {
      if (!Equal(board, p.second)) {
        moved = true;
        best = max(best, Expectimax(p.second, depth - 1, false));
      }
    }

    if (!moved) {
      return Eval(board);
    }

    return best;
  } else {
    vector<pair<int, int>> spaces;

    for (int i = 0; i < kBoard; ++i) {
      for (int j = 0; j < kBoard; ++j) {
        if (board[i][j] == 0) {
          spaces.push_back({i, j});
        }
      }
    }

    if (spaces.empty()) {
      return Eval(board);
    }

    double sum = 0.0;

    for (auto &p : spaces) {
      Board temp = board;
      temp[p.first][p.second] = 2;
      sum += Expectimax(temp, depth - 1, true);
    }

    return sum / spaces.size();
  }
}

string Move(const Board &board) {
  double best_score = -1e9;
  string best_move = "";
  vector<pair<string, Board>> moves = {{"LEFT", Left(board)},
                                       {"UP", Up(board)},
                                       {"RIGHT", Right(board)},
                                       {"DOWN", Down(board)}};

  for (auto &p : moves) {
    if (!Equal(board, p.second)) {
      double score = Expectimax(p.second, kMaxDepth, false);

      if (score > best_score) {
        best_score = score;
        best_move = p.first;
      }
    }
  }

  return best_move;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Board board(kBoard, vector<int>(kBoard, 0));

  int x;
  cin >> x;

  if (x == -1) {
    return 0;
  }

  int r = (x - 1) / kBoard;
  int c = (x - 1) % kBoard;
  board[r][c] = 2;

  while (true) {
    string move = Move(board);

    if (move == "") {
      break;
    }

    cout << move << "\n";
    cout.flush();

    if (move == "LEFT") {
      board = Left(board);
    } else if (move == "RIGHT") {
      board = Right(board);
    } else if (move == "UP") {
      board = Up(board);
    } else if (move == "DOWN") {
      board = Down(board);
    }

    cin >> x;

    if (x == -1) {
      return 0;
    }

    r = (x - 1) / kBoard;
    c = (x - 1) % kBoard;
    board[r][c] = 2;
  }

  return 0;
}