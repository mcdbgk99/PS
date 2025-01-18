#include <bits/stdc++.h>
using namespace std;

constexpr vector<int64_t> kInitVector() {
  vector<int64_t> temp;
  temp.reserve(1024);
  temp.push_back(0);

  for (int a = 1; a <= 9; ++a) {
    int64_t num_a = a;
    temp.push_back(num_a);
    for (int b = 0; b < a; ++b) {
      int64_t num_b = num_a * 10 + b;
      temp.push_back(num_b);
      for (int c = 0; c < b; ++c) {
        int64_t num_c = num_b * 10 + c;
        temp.push_back(num_c);
        for (int d = 0; d < c; ++d) {
          int64_t num_d = num_c * 10 + d;
          temp.push_back(num_d);
          for (int e = 0; e < d; ++e) {
            int64_t num_e = num_d * 10 + e;
            temp.push_back(num_e);
            for (int f = 0; f < e; ++f) {
              int64_t num_f = num_e * 10 + f;
              temp.push_back(num_f);
              for (int g = 0; g < f; ++g) {
                int64_t num_g = num_f * 10 + g;
                temp.push_back(num_g);
                for (int h = 0; h < g; ++h) {
                  int64_t num_h = num_g * 10 + h;
                  temp.push_back(num_h);
                  for (int i = 0; i < h; ++i) {
                    int64_t num_i = num_h * 10 + i;
                    temp.push_back(num_i);
                    for (int j = 0; j < i; ++j) {
                      int64_t num_j = num_i * 10 + j;
                      temp.push_back(num_j);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  sort(temp.begin(), temp.end());

  return temp;
}

auto v = kInitVector();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  if (n < v.size()) {
    cout << v[n];
  } else {
    cout << -1;
  }

  return 0;
}