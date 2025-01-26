#pragma GCC optimize("O3")
#include <stdio.h>

#include <deque>
#include <vector>
using namespace std;

inline int readChar();
template <class T = int>
inline T readInt();
template <class T>
inline void writeInt(T x, char end = 0);
inline void writeChar(int x);
inline void writeWord(const char *s);
static const int buf_size = 1 << 18;
inline int getChar() {
  static char buf[buf_size];
  static int len = 0, pos = 0;
  if (pos == len) pos = 0, len = fread(buf, 1, buf_size, stdin);
  if (pos == len) return -1;
  return buf[pos++];
}
inline int readChar() {
  int c = getChar();
  while (c <= 32) c = getChar();
  return c;
}
template <class T>
inline T readInt() {
  int s = 1, c = readChar();
  T x = 0;
  if (c == '-') s = -1, c = getChar();
  while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getChar();
  return s == 1 ? x : -x;
}
static int write_pos = 0;
static char write_buf[buf_size];
inline void writeChar(int x) {
  if (write_pos == buf_size)
    fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
  write_buf[write_pos++] = x;
}
template <class T>
inline void writeInt(T x, char end) {
  if (x < 0) writeChar('-'), x = -x;
  char s[24];
  int n = 0;
  while (x || !n) s[n++] = '0' + x % 10, x /= 10;
  while (n--) writeChar(s[n]);
  if (end) writeChar(end);
}
inline void writeWord(const char *s) {
  while (*s) writeChar(*s++);
}
struct Flusher {
  ~Flusher() {
    if (write_pos) fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
  }
} flusher;

int main() {
  int t = readInt();

  while (t--) {
    int n = readInt();
    int k = readInt();

    vector<int> costs(n + 1);
    vector<vector<int>> nodes(n + 1, vector<int>());

    for (int i = 1; i <= n; ++i) {
      costs[i] = readInt();
    }

    for (int i = 0; i < k; ++i) {
      int x = readInt();
      int y = readInt();
      nodes[y].push_back(x);
    }

    int w = readInt();

    vector<int> dp(n + 1, -1);
    deque<tuple<int, bool>> dq;

    dq.push_back({w, false});

    while (!dq.empty()) {
      auto [now_node, now_built] = dq.back();
      dq.pop_back();

      if (now_built) {
        int max_cost = 0;
        for (int new_node : nodes[now_node]) {
          max_cost = max(max_cost, dp[new_node]);
        }
        dp[now_node] = max_cost + costs[now_node];
      } else {
        if (dp[now_node] != -1) {
          continue;
        }

        dq.push_back({now_node, true});
        for (int i = nodes[now_node].size() - 1; i >= 0; --i) {
          dq.push_back({nodes[now_node][i], false});
        }
      }
    }

    writeInt(dp[w], '\n');
  }

  return 0;
}