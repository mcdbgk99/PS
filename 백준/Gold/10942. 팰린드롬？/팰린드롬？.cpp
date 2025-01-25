#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

inline int readChar();
template <class T = int>
inline T readInt();
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
  while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getChar();
  return x;
}
constexpr int OUT_BUF_SIZE = 1 << 16;
static char out_buf[OUT_BUF_SIZE];
static size_t out_pos = 0;
inline void flush() {
  if (out_pos == 0) return;
  write(STDOUT_FILENO, out_buf, out_pos);
  out_pos = 0;
}
inline void writeChar(char c) {
  if (out_pos == OUT_BUF_SIZE) flush();
  out_buf[out_pos++] = c;
}
inline void writeWord(const char *s) {
  while (*s) writeChar(*s++);
}
struct Flusher {
  ~Flusher() { flush(); }
} flusher;

constexpr uint32_t kCompileTimeHash(char *str, uint32_t seed = 0) {
  return *str ? kCompileTimeHash(str + 1, seed * 88848 + *str) : seed;
}
constexpr uint32_t kDateTimeHash = kCompileTimeHash(__DATE__ __TIME__);
constexpr uint32_t kFileHash = kCompileTimeHash(__FILE__);
constexpr uint64_t kMakeHash(uint64_t hash) {
  hash ^= hash >> 33;
  hash *= 0xff51afd7ed558ccdULL;
  hash ^= hash >> 33;
  hash *= 0xc4ceb9fe1a85ec53ULL;
  hash ^= hash >> 33;
  return hash;
}
constexpr uint64_t kHashBase = kMakeHash(kDateTimeHash ^ kFileHash);
constexpr int kMaxN = 2000;

constexpr auto kMakeHashPower() {
  array<uint64_t, kMaxN + 2> arr{1};
  for (int i = 1; i <= kMaxN; ++i) {
    arr[i] = arr[i - 1] * kHashBase;
  }
  return arr;
}
constexpr auto kHashPower = kMakeHashPower();

int main() {
  const int n = readInt();

  vector<int> v(n + 1);

  [[assume(n >= 1 && n <= 2000)]];
  for (int i = 1; i <= n; ++i) {
    v[i] = readInt();
  }

  vector<uint64_t> hash_prefix(n + 2, 0);
  vector<uint64_t> hash_suffix(n + 2, 0);

  for (int i = 1; i <= n; ++i) {
    hash_prefix[i] = hash_prefix[i - 1] * kHashBase + v[i];
    hash_suffix[i] = hash_suffix[i - 1] * kHashBase + v[n - i + 1];
  }

  const int m = readInt();

  [[assume(m >= 1 && m <= 1000000)]];
  for (int i = 0; i < m; ++i) {
    int s_forward = readInt();
    int e_forward = readInt();

    if (s_forward == e_forward) {
      writeChar('1');
    } else if (e_forward - s_forward == 2) {
      writeChar(v[s_forward] == v[e_forward] ? '1' : '0');
    } else {
      int s_backward = n - e_forward + 1;
      int e_backward = n - s_forward + 1;

      uint64_t hash_forward =
          hash_prefix[e_forward] -
          hash_prefix[s_forward - 1] * kHashPower[e_forward - s_forward + 1];
      uint64_t hash_backward =
          hash_suffix[e_backward] -
          hash_suffix[s_backward - 1] * kHashPower[e_backward - s_backward + 1];
      writeChar(hash_forward == hash_backward ? '1' : '0');
    }
    writeChar('\n');
  }

  return 0;
}