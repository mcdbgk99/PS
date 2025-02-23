#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Node {
  i64 t;
  int p;
};

struct Event {
  i64 t;
  vector<int> p;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<i64> t(n + 1);

  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
  }

  auto cmp = [](Node &a, Node &b) {
    if (a.t != b.t) {
      return a.t > b.t;
    }

    return a.p > b.p;
  };
  priority_queue<Node, vector<Node>, decltype(cmp)> pq;

  for (int i = 1; i <= k; ++i) {
    pq.push({t[i], i});
  }

  vector<Event> v;
  int cow = k + 1;
  v.reserve(n / max(1, k));

  while (cow <= n) {
    i64 i = pq.top().t;
    vector<int> temp;

    while (!pq.empty() && pq.top().t == i) {
      temp.push_back(pq.top().p);
      pq.pop();
    }

    for (int j : temp) {
      if (cow <= n) {
        pq.push({i + t[cow++], j});
      }
    }

    v.push_back({i, move(temp)});
  }

  i64 x = pq.top().t;
  vector<int> temp;

  while (!pq.empty() && pq.top().t == x) {
    temp.push_back(pq.top().p);
    pq.pop();
  }
  v.push_back({x, temp});

  vector<char> result(k + 1, '0');

  for (int i : v.back().p) {
    result[i] = '1';
  }

  for (int i = v.size() - 2; i >= 0; --i) {
    bool b = false;

    for (int j : v[i].p) {
      if (result[j] == '1') {
        b = true;
        break;
      }
    }

    if (b) {
      for (int j : v[i].p) {
        result[j] = '1';
      }
    }
  }

  cout << x << "\n";
  for (int i = 1; i <= k; ++i) {
    cout << result[i];
  }

  return 0;
}