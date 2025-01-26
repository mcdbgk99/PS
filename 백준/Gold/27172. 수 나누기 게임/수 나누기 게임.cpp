#pragma GCC optimize("O3")
#pragma comment(linker, "/STACK:336777216")
#include <stdio.h>
#include <unistd.h>

#include <array>
#include <bitset>
#include <vector>
using namespace std;

constexpr int kMax = 1000000 + 1;
array<int, kMax> divs{};
array<int, kMax> muls{};

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
  int n = readInt();

  vector<int> v(n);
  bitset<kMax> bs;

  for (int i = 0; i < n; ++i) {
    v[i] = readInt();
    bs[v[i]] = 1;
  }

  for (int i = 1; i < kMax; ++i) {
    if (!bs[i]) {
      continue;
    }

    for (int j = i; j < kMax; j += i) {
      ++divs[j];
      if (j != i && bs[j]) {
        ++muls[i];
      }
    }
  }

  for (int i : v) {
    writeInt(muls[i] - divs[i] + 1, ' ');
  }

  return 0;
}