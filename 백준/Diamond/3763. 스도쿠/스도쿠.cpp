#include <bits/stdc++.h>
using namespace std;

constexpr int kNodeSize = 20000;
constexpr int kMaxN = 16;
constexpr int kBoardSize = kMaxN * kMaxN;
constexpr int kBlockSize = 4;

class DancingLinks {
 public:
  vector<int> up, down, left, right;
  vector<int> column, row_id;
  vector<int> header_size;
  int column_count;
  int node_count;

  void AdjustSize(int index) {
    if (index >= left.size()) {
      int n = max<int>(index + 1, left.size() * 2);
      left.resize(n);
      right.resize(n);
      up.resize(n);
      down.resize(n);
      column.resize(n);
      row_id.resize(n);
    }
  }

  DancingLinks(int cols) {
    up.resize(kNodeSize);
    down.resize(kNodeSize);
    left.resize(kNodeSize);
    right.resize(kNodeSize);
    column.resize(kNodeSize);
    row_id.resize(kNodeSize);
    header_size.resize(cols + 1, 0);
    column_count = cols;
    node_count = cols + 1;

    for (int i = 0; i <= cols; ++i) {
      up[i] = i;
      down[i] = i;
      left[i] = i - 1;
      right[i] = i + 1;
      column[i] = i;
    }
    left[0] = cols;
    right[cols] = 0;
  }

  void AddMatrixRow(int row, const vector<int> &cols) {
    int first = -1;

    for (int col : cols) {
      int node = node_count++;
      AdjustSize(node);

      column[node] = col;
      row_id[node] = row;

      up[node] = up[col];
      down[node] = col;
      down[up[col]] = node;
      up[col] = node;
      ++header_size[col];

      if (first != -1) {
        left[node] = left[first];
        right[node] = first;
        right[left[first]] = node;
        left[first] = node;
      } else {
        first = node;
        left[node] = right[node] = node;
      }
    }
  }

  void Cover(int col) {
    left[right[col]] = left[col];
    right[left[col]] = right[col];

    for (int i = down[col]; i != col; i = down[i]) {
      for (int j = right[i]; j != i; j = right[j]) {
        up[down[j]] = up[j];
        down[up[j]] = down[j];
        --header_size[column[j]];
      }
    }
  }

  void Uncover(int col) {
    for (int i = up[col]; i != col; i = up[i]) {
      for (int j = left[i]; j != i; j = left[j]) {
        up[down[j]] = j;
        down[up[j]] = j;
        ++header_size[column[j]];
      }
    }

    left[right[col]] = col;
    right[left[col]] = col;
  }
};

bool Backtrack(DancingLinks &dlx, vector<int> &best, vector<int> &now) {
  if (dlx.right[0] == 0) {
    best = now;
    return true;
  }

  int col = dlx.right[0];
  for (int now_col = dlx.right[0]; now_col != 0; now_col = dlx.right[now_col]) {
    if (dlx.header_size[now_col] < dlx.header_size[col]) {
      col = now_col;
    }
  }

  dlx.Cover(col);

  for (int row = dlx.down[col]; row != col; row = dlx.down[row]) {
    now.push_back(dlx.row_id[row]);

    for (int i = dlx.right[row]; i != row; i = dlx.right[i]) {
      dlx.Cover(dlx.column[i]);
    }

    if (Backtrack(dlx, best, now)) {
      return true;
    }

    for (int i = dlx.left[row]; i != row; i = dlx.left[i]) {
      dlx.Uncover(dlx.column[i]);
    }

    now.pop_back();
  }

  dlx.Uncover(col);

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<vector<int>> board(kMaxN, vector<int>(kMaxN));
  for (int y = 0; y < kMaxN; ++y) {
    for (int x = 0; x < kMaxN; ++x) {
      char c;
      cin >> c;
      if (c == '-') {
        board[y][x] = 0;
      } else {
        board[y][x] = c - 'A' + 1;
      }
    }
  }

  DancingLinks dlx(kBoardSize * 4);
  vector<int> row_front(kBoardSize * kMaxN, -1);

  for (int y = 0; y < kMaxN; ++y) {
    for (int x = 0; x < kMaxN; ++x) {
      for (int cell = (board[y][x] ? board[y][x] : 1);
           cell <= (board[y][x] ? board[y][x] : kMaxN); ++cell) {
        int row = y * kBoardSize + x * kMaxN + (cell - 1);
        vector<int> cols;
        cols.push_back(y * kMaxN + x + 1);
        cols.push_back(kBoardSize * 1 + y * kMaxN + (cell - 1) + 1);
        cols.push_back(kBoardSize * 2 + x * kMaxN + (cell - 1) + 1);
        cols.push_back(kBoardSize * 3 +
                       ((y / kBlockSize) * kBlockSize + (x / kBlockSize)) *
                           kMaxN +
                       (cell - 1) + 1);
        row_front[row] = dlx.node_count;
        dlx.AddMatrixRow(row, cols);
      }
    }
  }

  vector<int> temp;

  for (int y = 0; y < kMaxN; ++y) {
    for (int x = 0; x < kMaxN; ++x) {
      if (board[y][x]) {
        int cell = board[y][x];
        int row = y * kBoardSize + x * kMaxN + (cell - 1);
        int f = row_front[row];
        int node = f;
        do {
          dlx.Cover(dlx.column[node]);
          node = dlx.right[node];
        } while (node != f);
        temp.push_back(row);
      }
    }
  }

  vector<int> result;
  Backtrack(dlx, temp, result);

  for (int e : result) {
    int r = e % kBoardSize;
    int y = e / kBoardSize;
    int x = r / kMaxN;
    board[y][x] = (r % kMaxN) + 1;
  }

  for (int y = 0; y < kMaxN; ++y) {
    for (int x = 0; x < kMaxN; ++x) {
      cout << static_cast<char>(board[y][x] + 'A' - 1);
    }
    cout << "\n";
  }

  return 0;
}