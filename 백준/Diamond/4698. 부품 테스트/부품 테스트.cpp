#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (true) {
    int n, m;
    cin >> n >> m;

    if (n == 0 && m == 0) {
      break;
    }

    vector<array<int64_t, 2>> classes(n);
    int64_t part_sum = 0;
    int64_t need_review = 0;

    for (int i = 0; i < n; ++i) {
      int64_t j, c;
      cin >> j >> c;
      classes[i] = {j, c};
      part_sum += j;
      need_review += j * c;
    }

    vector<array<int64_t, 2>> engineers(m);
    int64_t engineer_sum = 0;
    int64_t review_sum = 0;

    for (int i = 0; i < m; ++i) {
      int64_t k, d;
      cin >> k >> d;
      engineers[i] = {k, d};
      engineer_sum += k;
      review_sum += k * d;
    }

    if (need_review > review_sum) {
      cout << "0\n";
      continue;
    }

    bool skip = false;

    for (int i = 0; i < n; ++i) {
      if (classes[i][1] > engineer_sum) {
        skip = true;
        break;
      }
    }

    if (skip) {
      cout << "0\n";
      continue;
    }

    sort(classes.begin(), classes.end(),
         [](const array<int64_t, 2>& left, const array<int64_t, 2>& right) {
           return left[1] > right[1];
         });
    sort(engineers.begin(), engineers.end(),
         [](const array<int64_t, 2>& left, const array<int64_t, 2>& right) {
           return left[1] < right[1];
         });

    vector<int64_t> part_psum(n + 1, 0), need_psum(n + 1, 0);

    for (int i = 0; i < n; ++i) {
      part_psum[i + 1] = part_psum[i] + classes[i][0];
      need_psum[i + 1] = need_psum[i] + classes[i][0] * classes[i][1];
    }

    vector<int64_t> engineer_psum(m + 1, 0), review_psum(m + 1, 0);

    for (int i = 0; i < m; ++i) {
      engineer_psum[i + 1] = engineer_psum[i] + engineers[i][0];
      review_psum[i + 1] = review_psum[i] + engineers[i][0] * engineers[i][1];
    }

    vector<int64_t> verify;
    verify.reserve(n + m + 2);
    verify.push_back(1);
    verify.push_back(part_sum);

    for (int i = 1; i <= n; ++i) {
      if (part_psum[i] >= 1 && part_psum[i] <= part_sum) {
        verify.push_back(part_psum[i]);
      }
    }

    for (int i = 0; i < m; ++i) {
      if (engineers[i][1] >= 1 && engineers[i][1] <= part_sum) {
        verify.push_back(engineers[i][1]);
      }
    }

    sort(verify.begin(), verify.end());
    verify.erase(unique(verify.begin(), verify.end()), verify.end());

    auto get_need = [&classes, &part_psum, &need_psum, n](int64_t i) {
      int index = lower_bound(part_psum.begin(), part_psum.end(), i) -
                  part_psum.begin();

      return need_psum[index - 1] +
             (i - part_psum[index - 1]) * classes[index - 1][1];
    };

    auto get_review = [&engineers, &engineer_psum, &review_psum, m](int64_t i) {
      int index = upper_bound(engineers.begin(), engineers.end(), i,
                              [](int64_t i, const array<int64_t, 2>& arr) {
                                return i < arr[1];
                              }) -
                  engineers.begin();

      return review_psum[index] + (engineer_psum[m] - engineer_psum[index]) * i;
    };

    skip = false;

    for (int64_t i : verify) {
      if (get_need(i) > get_review(i)) {
        skip = true;
        break;
      }
    }

    cout << (skip ? "0\n" : "1\n");
  }

  return 0;
}