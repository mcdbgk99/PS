#include <bits/stdc++.h>
using namespace std;

constexpr int64_t kMod = 1000000007;

class TreePath {
 private:
  int n, q, log_n;
  vector<vector<int>> adj, ancestor;
  vector<int> parent, depth, sub_size;
  vector<int64_t> up_sum, down_sum;

  void DfsSubSize(int v, int p) {
    parent[v] = p;
    depth[v] = (p == -1 ? 0 : depth[p] + 1);
    sub_size[v] = 1;

    for (int i : adj[v]) {
      if (i == p) {
        continue;
      }

      DfsSubSize(i, v);
      sub_size[v] += sub_size[i];
    }
  }

  void DfsSum(int v, int p, int64_t now_up_sum, int64_t now_down_sum) {
    up_sum[v] = now_up_sum;
    down_sum[v] = now_down_sum;

    for (int i : adj[v]) {
      if (i == p) {
        continue;
      }

      int64_t add_up = (sub_size[i] * 2 - 1) % kMod;

      if (add_up < 0) {
        add_up += kMod;
      }

      int64_t add_down = ((n - sub_size[i]) * 2 - 1) % kMod;

      if (add_down < 0) {
        add_down += kMod;
      }

      DfsSum(i, v, (now_up_sum + add_up) % kMod,
             (now_down_sum + add_down) % kMod);
    }
  }

  void BuildLcaTable() {
    for (int i = 1; i <= n; ++i) {
      ancestor[i][0] = parent[i];
    }

    for (int j = 1; j < log_n; ++j) {
      for (int i = 1; i <= n; ++i) {
        if (ancestor[i][j - 1] != -1) {
          ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];
        } else {
          ancestor[i][j] = -1;
        }
      }
    }
  }

  int GetLca(int a, int b) {
    if (depth[a] < depth[b]) {
      swap(a, b);
    }

    int depth_diff = depth[a] - depth[b];

    for (int i = 0; i < log_n; ++i) {
      if (depth_diff & (1 << i)) {
        a = ancestor[a][i];
      }
    }

    if (a == b) {
      return a;
    }

    for (int i = log_n - 1; i >= 0; --i) {
      if (ancestor[a][i] != ancestor[b][i]) {
        a = ancestor[a][i];
        b = ancestor[b][i];
      }
    }

    return parent[a];
  }

 public:
  TreePath(int n, int q, const vector<vector<int>>& adj)
      : n(n),
        q(q),
        adj(adj),
        parent(n + 1),
        depth(n + 1),
        sub_size(n + 1),
        up_sum(n + 1),
        down_sum(n + 1),
        log_n(32 - __builtin_clz(n)),
        ancestor(n + 1, vector<int>(log_n, -1)) {}

  void Init() {
    DfsSubSize(1, -1);
    DfsSum(1, -1, 0, 0);
    BuildLcaTable();
  }

  int64_t Query(int a, int b) {
    int lca = GetLca(a, b);
    int64_t result = ((up_sum[a] - up_sum[lca]) % kMod +
                      (down_sum[b] - down_sum[lca]) % kMod) %
                     kMod;

    if (result < 0) {
      result += kMod;
    }

    return result % kMod;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  vector<vector<int>> adj(n + 1);

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  TreePath tree(n, q, adj);
  tree.Init();

  for (int i = 0; i < q; ++i) {
    int a, b;
    cin >> a >> b;
    cout << tree.Query(a, b) << "\n";
  }

  return 0;
}