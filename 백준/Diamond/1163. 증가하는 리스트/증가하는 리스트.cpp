#include <bits/stdc++.h>
using namespace std;

const string kInvalid = "X";
string input;
unordered_map<string, string> dp;

bool IsValidPattern(const string& pattern) {
  for (char c : pattern) {
    if (c != '?' && !isdigit(c)) {
      return false;
    }
  }

  return true;
}

string MakeToken(const string& pattern) {
  string result;

  for (int i = 0; i < pattern.size(); ++i) {
    if (pattern[i] != '?') {
      result.push_back(pattern[i]);
    } else {
      result.push_back(i == 0 ? '1' : '0');
    }
  }

  if (result == "0") {
    return kInvalid;
  }

  if (result.size() > 1 && result[0] == '0') {
    return kInvalid;
  }

  return result;
}

string FindToken(const string& pattern, const string& str) {
  int n = pattern.size();
  vector<vector<string>> memo(n + 1, vector<string>(2, kInvalid));
  memo[n][1] = "";

  for (int i = n - 1; i >= 0; --i) {
    for (int bigger = 0; bigger <= 1; ++bigger) {
      char start = '0';

      if (i == 0) {
        start = '1';
      }

      if (!bigger) {
        start = max(start, str[i]);
      }

      string best = kInvalid;

      for (char j = start; j <= '9'; ++j) {
        if (pattern[i] != '?' && pattern[i] != j) {
          continue;
        }

        int k = bigger;
        if (!bigger) {
          if (j > str[i]) {
            k = 1;
          } else if (j < str[i]) {
            continue;
          }
        }

        if (memo[i + 1][k] == kInvalid) {
          continue;
        }

        string temp = string(1, j) + memo[i + 1][k];

        if (best == kInvalid || temp < best) {
          best = temp;

          if (best == temp) {
            break;
          }
        }
      }

      memo[i][bigger] = best;
    }
  }

  return memo[0][0];
}

string Dp(const string& str, int index) {
  if (index >= input.size()) {
    return kInvalid;
  }

  string key = to_string(index) + ":" + str;
  if (dp.find(key) != dp.end()) {
    return dp[key];
  }

  string best = kInvalid;

  for (int i = index + 1; i <= input.size(); ++i) {
    string pattern = input.substr(index, i - index);
    if (!IsValidPattern(pattern)) {
      continue;
    }

    if (!str.empty() && pattern.size() < str.size()) {
      continue;
    }

    string token;
    if (str.empty() || str.size() < pattern.size()) {
      token = MakeToken(pattern);
    } else if (str.size() == pattern.size()) {
      token = FindToken(pattern, str);
    }

    if (token == kInvalid || token == "0") {
      continue;
    }

    if (i == input.size()) {
      if (best == kInvalid || token < best) {
        best = token;
      }

      continue;
    }

    if (input[i] != '?' && input[i] != ',') {
      continue;
    }

    if (i + 1 >= input.size()) {
      continue;
    }

    string temp = Dp(token, i + 1);
    if (temp == kInvalid) {
      continue;
    }

    temp = token + "," + temp;
    if (best == kInvalid || temp < best) {
      best = temp;
    }
  }

  return dp[key] = best;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> input;

  string result = Dp("", 0);
  cout << (result == kInvalid ? "-1" : result);

  return 0;
}