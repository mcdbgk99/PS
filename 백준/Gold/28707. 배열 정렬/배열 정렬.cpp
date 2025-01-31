#include <bits/stdc++.h>
using namespace std;

inline uint32_t Encode(vector<int>& v) {
  uint32_t encoded = 0;
  for (int i = 0; i < v.size(); ++i) {
    encoded |= (v[i] << (i * 4));
  }
  return encoded;
}

inline vector<int> Decode(uint32_t encoded, int n) {
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    v[i] = (encoded >> (i * 4)) & 0xF;
  }
  return v;
}

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  int m;
  cin >> m;

  vector<tuple<int, int, int>> swaps(m);
  for (int i = 0; i < m; ++i) {
    cin >> get<0>(swaps[i]) >> get<1>(swaps[i]) >> get<2>(swaps[i]);
    --get<0>(swaps[i]);
    --get<1>(swaps[i]);
  }

  vector<int> v_sorted = v;
  sort(v_sorted.begin(), v_sorted.end());
  uint32_t v_sorted_encoded = Encode(v_sorted);

  int result = -1;
  auto cmp = [](tuple<int, uint32_t>& left, tuple<int, uint32_t>& right) {
    return get<0>(left) > get<0>(right);
  };
  priority_queue<tuple<int, uint32_t>, vector<tuple<int, uint32_t>>,
                 decltype(cmp)>
      pq;
  unordered_map<uint32_t, int> costs;

  uint32_t temp = Encode(v);
  pq.push({0, temp});
  costs[temp] = 0;

  while (!pq.empty()) {
    auto [now_cost, now_encoded] = pq.top();
    pq.pop();

    if (now_cost > costs[now_encoded]) {
      continue;
    }

    if (now_encoded == v_sorted_encoded) {
      cout << now_cost;
      return 0;
    }

    vector<int> decoded = Decode(now_encoded, n);
    for (auto [l, r, c] : swaps) {
      swap(decoded[l], decoded[r]);
      uint32_t new_encoded = Encode(decoded);

      int new_cost = now_cost + c;
      auto it = costs.find(new_encoded);

      if (it == costs.end() || new_cost < it->second) {
        costs[new_encoded] = new_cost;
        pq.push({new_cost, new_encoded});
      }
      swap(decoded[l], decoded[r]);
    }
  }

  cout << result;

  return 0;
}