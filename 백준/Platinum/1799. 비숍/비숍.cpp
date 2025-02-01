// https://github.com/KarlHajal/DLX-Sudoku-Solver

#include <bits/stdc++.h>
using namespace std;

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
    up.resize(3000);
    down.resize(3000);
    left.resize(3000);
    right.resize(3000);
    column.resize(3000);
    row_id.resize(3000);
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

  void AddMatrixRow(int row, vector<int>&& cols) {
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

int Backtrack(DancingLinks& dlx, int& best, int now,
              vector<int>& is_dummy_row) {
  if (dlx.right[0] == 0) {
    return min(best, now);
  }

  if (now >= best) {
    return best;
  }

  int col = dlx.right[0];
  for (int new_col = dlx.right[0]; new_col != 0; new_col = dlx.right[new_col]) {
    if (dlx.header_size[new_col] < dlx.header_size[col]) {
      col = new_col;
    }
  }

  dlx.Cover(col);

  for (int row = dlx.down[col]; row != col; row = dlx.down[row]) {
    int added = is_dummy_row[dlx.row_id[row] - 1] ? 1 : 0;

    for (int i = dlx.right[row]; i != row; i = dlx.right[i]) {
      dlx.Cover(dlx.column[i]);
    }

    best = Backtrack(dlx, best, now + added, is_dummy_row);

    for (int i = dlx.right[row]; i != row; i = dlx.right[i]) {
      dlx.Uncover(dlx.column[i]);
    }
  }

  dlx.Uncover(col);

  return best;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<int>> board(n, vector<int>(n));

  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      cin >> board[y][x];
    }
  }

  int board_size = board.size();
  int dlx_size = 4 * board_size - 2;

  DancingLinks dlx(dlx_size);
  vector<int> is_dummy_row;
  int row_index = 0;

  for (int i = 0; i < board_size; ++i) {
    for (int j = 0; j < board_size; ++j) {
      if (board[i][j]) {
        is_dummy_row.push_back(0);
        int forward = (i - j) + board_size;
        int backward = (i + j) + 2 * board_size;
        dlx.AddMatrixRow(++row_index, {forward, backward});
      }
    }
  }

  for (int i = 1; i <= dlx_size; ++i) {
    is_dummy_row.push_back(1);
    dlx.AddMatrixRow(++row_index, {i});
  }

  int dummy = INT_MAX;
  Backtrack(dlx, dummy, 0, is_dummy_row);

  cout << (dlx_size - dummy) / 2;

  return 0;
}