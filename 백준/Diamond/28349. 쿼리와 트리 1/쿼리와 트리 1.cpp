#include <bits/stdc++.h>
using namespace std;

struct Con {
  int u, v, w;
};

struct Segment {
  int parent;
  vector<int> nodes;
  vector<Con> cons;
};

bool CheckNode(int x, vector<int> &nodes, vector<Con> &cons,
               unordered_map<int, int> &m, vector<int> &dfs_parent) {
  vector<vector<int>> adj(nodes.size());

  for (auto &c : cons) {
    if (c.w == x) {
      continue;
    }

    if (m.find(c.u) == m.end() || m.find(c.v) == m.end() ||
        m.find(c.w) == m.end()) {
      continue;
    }

    int u = m[c.u], v = m[c.v], w = m[c.w];

    adj[u].push_back(w);
    adj[v].push_back(u);
    adj[w].push_back(v);
  }

  dfs_parent.assign(nodes.size(), -1);
  int id = 0;

  for (int i = 0; i < nodes.size(); ++i) {
    if (dfs_parent[i] == -1) {
      stack<int> st;

      dfs_parent[i] = id;
      st.push(i);

      while (!st.empty()) {
        int u = st.top();
        st.pop();

        for (int v : adj[u]) {
          if (dfs_parent[v] == -1) {
            dfs_parent[v] = id;
            st.push(v);
          }
        }
      }

      ++id;
    }
  }

  for (auto &c : cons) {
    if (c.w != x) {
      continue;
    }

    if (m.find(c.u) == m.end() || m.find(c.v) == m.end()) {
      continue;
    }

    if (dfs_parent[m[c.u]] == dfs_parent[m[c.v]]) {
      return false;
    }
  }

  return true;
}

vector<Segment> MakeSegment(Segment &seg, int x, unordered_map<int, int> &m,
                            vector<int> &comp) {
  unordered_map<int, vector<int>> groups;

  for (int i = 0; i < seg.nodes.size(); ++i) {
    int node = seg.nodes[i];

    if (node == x) {
      continue;
    }

    groups[comp[i]].push_back(node);
  }

  vector<Segment> result;

  for (auto &p : groups) {
    Segment temp;
    temp.parent = x;
    temp.nodes = p.second;

    unordered_set<int> s(temp.nodes.begin(), temp.nodes.end());

    for (auto &c : seg.cons) {
      if (c.u == x || c.v == x || c.w == x) {
        continue;
      }

      if (s.find(c.u) != s.end() && s.find(c.v) != s.end() &&
          s.find(c.w) != s.end()) {
        temp.cons.push_back(c);
      }
    }

    result.push_back(temp);
  }

  return result;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<Con> cons;

    for (int i = 0; i < m; ++i) {
      Con c;
      cin >> c.u >> c.v >> c.w;
      cons.push_back(c);
    }

    bool possible = true;
    vector<int> result(n + 1, -1);
    stack<Segment> st;
    Segment temp;

    temp.parent = 0;
    for (int i = 1; i <= n; ++i) {
      temp.nodes.push_back(i);
    }
    temp.cons = cons;
    st.push(temp);

    while (!st.empty()) {
      Segment seg = st.top();
      st.pop();

      int nodes_size = seg.nodes.size();

      if (nodes_size == 0) {
        continue;
      } else if (nodes_size == 1) {
        int v = seg.nodes[0];

        if (result[v] == -1) {
          result[v] = seg.parent;
        }

        continue;
      }

      unordered_map<int, int> m;

      for (int i = 0; i < nodes_size; ++i) {
        m[seg.nodes[i]] = i;
      }

      vector<bool> forced(nodes_size, false);

      for (auto &c : seg.cons) {
        if (m.find(c.u) != m.end() && c.u != c.w) {
          forced[m[c.u]] = true;
        }

        if (m.find(c.v) != m.end() && c.v != c.w) {
          forced[m[c.v]] = true;
        }
      }

      int x = -1;
      vector<int> uf_parent;

      for (int i = 0; i < nodes_size; ++i) {
        if (!forced[i]) {
          int node = seg.nodes[i];
          vector<int> uf_parent_temp;

          if (CheckNode(node, seg.nodes, seg.cons, m, uf_parent_temp)) {
            x = node;
            uf_parent = uf_parent_temp;
            break;
          }
        }
      }

      if (x == -1) {
        for (int i = 0; i < nodes_size; ++i) {
          if (!forced[i]) {
            int node = seg.nodes[i];
            vector<int> uf_parent_temp;

            if (CheckNode(node, seg.nodes, seg.cons, m, uf_parent_temp)) {
              x = node;
              uf_parent = uf_parent_temp;
              break;
            }
          }
        }
      }

      if (x == -1) {
        possible = false;
        break;
      }

      result[x] = seg.parent;
      vector<Segment> segs = MakeSegment(seg, x, m, uf_parent);

      for (auto &s : segs) {
        st.push(s);
      }
    }

    if (!possible) {
      cout << "NIE\n";
    } else {
      for (int i = 1; i <= n; ++i) {
        if (result[i] == -1) {
          result[i] = 0;
        }
        cout << result[i] << " ";
      }
      cout << "\n";
    }
  }

  return 0;
}