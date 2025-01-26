#pragma GCC optimize("O3")
#pragma comment(linker, "/STACK:336777216")
#include <stdio.h>
#include <unistd.h>

#include <vector>
using namespace std;

inline char readChar();
template <class T = size_t>
inline T readInt();
template <class T>
inline void writeInt(T x, char end = 0);
inline void writeWord(const char* s);
static const size_t buf_size = 1 << 17;
static char buf[buf_size];
inline char getChar() {
  static size_t len = 0, pos = 0;
  if (pos == len) pos = 0, len = fread(buf, 1, buf_size, stdin);
  if (pos == len) return -1;
  return buf[pos++];
}
inline char readChar() {
  char c = getChar();
  while (c <= 32) c = getChar();
  return c;
}
template <class T>
inline T readInt() {
  char c = readChar();
  T x = 0;
  while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getChar();
  return x;
}
constexpr size_t OUT_BUF_SIZE = 1 << 8;
static char out_buf[OUT_BUF_SIZE];
static size_t out_pos = 0;
inline void flush() {
  if (out_pos == 0) return;
  write(STDOUT_FILENO, out_buf, out_pos);
  out_pos = 0;
}
inline void writeChar(char c) { out_buf[out_pos++] = c; }
inline void writeWord(const char* s) {
  while (*s) writeChar(*s++);
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
struct Flusher {
  ~Flusher() { flush(); }
} flusher;

inline void Union(vector<int>& points, int a, int b) {
  if (points[a] > points[b]) {
    swap(a, b);
  }

  points[a] += points[b];
  points[b] = a;
}

inline int Find(vector<int>& points, int x) {
  while (points[x] >= 0) {
    int p = points[x];
    if (points[p] >= 0) {
      points[x] = points[p];
    }
    x = p;
  }
  return x;
}

int main() {
  int n = readInt();
  int m = readInt();

  vector<int> points(n, -1);

  for (int i = 1; i <= m; i++) {
    int a = readInt();
    int b = readInt();
    a = Find(points, a);
    b = Find(points, b);

    if (a == b) {
      writeInt(i);
      flush();
      return 0;
    }

    Union(points, a, b);
  }

  writeChar('0');
  flush();

  return 0;
}