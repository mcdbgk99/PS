#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string n, m;
  cin >> n >> m;

  string q = "";
  string r = "";

  auto cmp = [](string &a, string &b) {
    if (a.size() < b.size()) {
      return -1;
    }

    if (a.size() > b.size()) {
      return 1;
    }

    if (a == b) {
      return 0;
    }

    return (a < b ? -1 : 1);
  };

  auto subtract = [&](string a, string &b) {
    int i = a.size() - 1, j = b.size() - 1;
    int carry = 0;

    while (j >= 0 || carry) {
      int sub = (a[i] - '0') - (j >= 0 ? b[j] - '0' : 0) - carry;
      if (sub < 0) {
        sub += 10;
        carry = 1;
      } else {
        carry = 0;
      }

      a[i] = sub + '0';
      --i;
      --j;
    }

    size_t pos = a.find_first_not_of('0');
    return ((pos != string::npos) ? a.substr(pos) : "0");
  };

  for (char c : n) {
    if (r == "0") {
      r = "";
    }

    r.push_back(c);
    size_t pos = r.find_first_not_of('0');
    r = ((pos != string::npos) ? r.substr(pos) : "0");

    int cnt = 0;
    while (cmp(r, m) >= 0) {
      ++cnt;
      r = subtract(r, m);
    }

    q.push_back(cnt + '0');
  }

  size_t pos = q.find_first_not_of('0');
  q = ((pos != string::npos) ? q.substr(pos) : "0");

  cout << q << "\n" << r;

  return 0;
}