#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int h;
  cin >> h;

  vector<int> v(h);

  for (int i = 0; i < h; ++i) {
    cin >> v[i];
  }

  int c, d;
  cin >> c >> d;

  vector<int> forward(h, 0), backward(h, 0);
  backward.back() = v.back();

  for (int i = 1; i < h; ++i) {
    int temp = v[i - 1] + forward[i - 1] * 8 - v[i];
    forward[i] = (temp < 0 ? 0 : temp / 8 + 1);
    if (forward[i] > v[i]) {
      cout << -1;
      return 0;
    }
  }

  for (int i = h - 2; i >= 0; --i) {
    int temp = v[i + 1] + backward[i + 1] * 8 - 1 - v[i];
    if (temp < 0) {
      cout << -1;
      return 0;
    }
    backward[i] = min(v[i], temp / 8);
    if (forward[i] > backward[i]) {
      cout << -1;
      return 0;
    }
  }

  int forward_sum = accumulate(forward.begin(), forward.end(), 0);
  int backward_sum = accumulate(backward.begin(), backward.end(), 0);

  if (d < forward_sum || d > backward_sum) {
    cout << -1;
    return 0;
  }

  int remain = d - forward_sum;
  for (int i = h - 1; i >= 0; --i) {
    int add = min(remain, backward[i] - forward[i]);
    forward[i] += add;
    remain -= add;
    if (remain <= 0) {
      break;
    }
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < forward[i]; ++j) {
      cout << "9 ";
    }

    for (int j = 0; j < v[i] - forward[i]; ++j) {
      cout << "1 ";
    }

    cout << "\n";
  }

  return 0;
}