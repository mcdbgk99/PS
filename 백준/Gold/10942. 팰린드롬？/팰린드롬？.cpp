#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<> dist(0x10203040, 0x50607080);
  uint64_t hash_base = dist(gen);

  int n;
  cin >> n;

  vector<int> v(n + 1);

  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
  }

  vector<uint64_t> hash_prefix(n + 2, 0);
  vector<uint64_t> hash_suffix(n + 2, 0);
  vector<uint64_t> hash_power(n + 2, 1);

  for (int i = 1; i <= n; ++i) {
    hash_power[i] = hash_power[i - 1] * hash_base;
    hash_prefix[i] = hash_prefix[i - 1] * hash_base + v[i];
    hash_suffix[i] = hash_suffix[i - 1] * hash_base + v[n - i + 1];
  }

  int m;
  cin >> m;

  for (int i = 0; i < m; ++i) {
    int s_forward, e_forward;
    cin >> s_forward >> e_forward;
    int s_backward = n - e_forward + 1;
    int e_backward = n - s_forward + 1;

    uint64_t hash_forward =
        hash_prefix[e_forward] -
        hash_prefix[s_forward - 1] * hash_power[e_forward - s_forward + 1];
    uint64_t hash_backward =
        hash_suffix[e_backward] -
        hash_suffix[s_backward - 1] * hash_power[e_backward - s_backward + 1];
    cout << (hash_forward == hash_backward) << "\n";
  }

  return 0;
}