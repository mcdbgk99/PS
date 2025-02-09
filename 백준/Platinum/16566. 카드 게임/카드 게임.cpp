#include <bits/stdc++.h>
using namespace std;

void RadixSort(vector<int> &v) {
  const int b = 8;
  const int bits = 32;
  const int buckets = 1 << b;
  const int n = v.size();

  vector<int> temp(n);

  for (int shift = 0; shift < bits; shift += b) {
    vector<int> count(buckets, 0);

    for (int i = 0; i < n; ++i) {
      int digit = (v[i] >> shift) & (buckets - 1);
      ++count[digit];
    }

    for (int i = 1; i < buckets; ++i) {
      count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; --i) {
      int digit = (v[i] >> shift) & (buckets - 1);
      temp[--count[digit]] = v[i];
    }

    v.swap(temp);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  vector<int> cards(m);
  vector<int> visited(m, 0);

  for (int i = 0; i < m; ++i) {
    cin >> cards[i];
  }

  RadixSort(cards);

  for (int i = 0; i < k; ++i) {
    int x;
    cin >> x;
    auto it = upper_bound(cards.begin(), cards.end(), x);
    int j = 0;
    while (visited[it - cards.begin() + j]) {
      ++j;
    }
    visited[it - cards.begin() + j] = 1;
    cout << *(it + j) << "\n";
  }

  return 0;
}