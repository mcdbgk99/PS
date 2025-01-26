#pragma GCC optimize("O3")
#include <stdio.h>

#include <algorithm>
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

vector<int> costs;
vector<vector<int>> nodes;
vector<int> in_degree;
vector<int> result;

int main() {
  int t = readInt();

  while (t--) {
    int n = readInt();
    int k = readInt();

    costs.resize(n + 1);
    nodes.assign(n + 1, vector<int>());
    in_degree.assign(n + 1, 0);
    result.assign(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
      costs[i] = readInt();
    }

    for (int i = 0; i < k; ++i) {
      int x = readInt();
      int y = readInt();
      nodes[x].push_back(y);
      in_degree[y]++;
    }

    int w = readInt();

    deque<int> dq;
    for (int i = 1; i <= n; ++i) {
      if (in_degree[i] == 0) {
        dq.push_back(i);
        result[i] = costs[i];
      }
    }

    while (!dq.empty()) {
      auto now_node = dq.front();
      dq.pop_front();

      if (now_node == w) {
        break;
      }

      for (int new_node : nodes[now_node]) {
        result[new_node] =
            max(result[new_node], result[now_node] + costs[new_node]);
        if (--in_degree[new_node] == 0) {
          dq.push_back(new_node);
        }
      }
    }

    writeInt(result[w], '\n');
  }

  return 0;
}