#pragma GCC optimize("O3")
#include <bits/stdc++.h>
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
  mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<> dist(0x12341234, 0x56785678);
  uint64_t hash_base = dist(gen);

  int n = readInt();

  vector<int> v(n + 1);

  for (int i = 1; i <= n; ++i) {
    v[i] = readInt();
  }

  vector<uint64_t> hash_prefix(n + 2, 0);
  vector<uint64_t> hash_suffix(n + 2, 0);
  vector<uint64_t> hash_power(n + 2, 1);

  for (int i = 1; i <= n; ++i) {
    hash_power[i] = hash_power[i - 1] * hash_base;
    hash_prefix[i] = hash_prefix[i - 1] * hash_base + v[i];
    hash_suffix[i] = hash_suffix[i - 1] * hash_base + v[n - i + 1];
  }

  int m = readInt();

  for (int i = 0; i < m; ++i) {
    int s_forward = readInt();
    int e_forward = readInt();
    int s_backward = n - e_forward + 1;
    int e_backward = n - s_forward + 1;

    uint64_t hash_forward =
        hash_prefix[e_forward] -
        hash_prefix[s_forward - 1] * hash_power[e_forward - s_forward + 1];
    uint64_t hash_backward =
        hash_suffix[e_backward] -
        hash_suffix[s_backward - 1] * hash_power[e_backward - s_backward + 1];
    writeChar(hash_forward == hash_backward ? '1' : '0');
    writeChar('\n');
  }

  return 0;
}