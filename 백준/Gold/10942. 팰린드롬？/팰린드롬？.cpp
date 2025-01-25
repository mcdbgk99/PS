#pragma GCC optimize("O3")
#pragma comment(linker, "/STACK:336777216")
#include <stdio.h>
#include <unistd.h>

#include <array>
#include <vector>
using namespace std;

inline char readChar();
template <class T = int>
inline T readInt();
inline void writeWord(const char *s);
static const int buf_size = 1 << 18;
static char buf[buf_size];
inline char getChar() {
  static int len = 0, pos = 0;
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

constexpr unsigned long kCompileTimeHash(char *str, unsigned long seed = 0) {
  return *str ? kCompileTimeHash(str + 1, seed * 88848 + *str) : seed;
}
constexpr unsigned long kDateTimeHash = kCompileTimeHash(__DATE__ __TIME__);
constexpr unsigned long kFileHash = kCompileTimeHash(__FILE__);
constexpr unsigned long long kMakeHash(unsigned long long hash) {
  hash ^= hash >> 33;
  hash *= 0xff51afd7ed558ccdULL;
  hash ^= hash >> 33;
  hash *= 0xc4ceb9fe1a85ec53ULL;
  hash ^= hash >> 33;
  return hash;
}
constexpr unsigned long long kHashBase = kMakeHash(kDateTimeHash ^ kFileHash);
constexpr int kMaxN = 2000;

constexpr auto kMakeHashPower() {
  array<unsigned long long, kMaxN + 2> arr{1};
  for (int i = 1; i <= kMaxN; ++i) {
    arr[i] = arr[i - 1] * kHashBase;
  }
  return arr;
}
constexpr auto kHashPower = kMakeHashPower();

int main() {
  const int n = readInt();

  array<int, kMaxN + 1> v{};

  [[assume(n >= 1 && n <= 2000)]];
  for (int i = 1; i <= n; ++i) {
    v[i] = readInt();
  }

  array<unsigned long long, kMaxN + 2> hash_prefix{};
  array<unsigned long long, kMaxN + 2> hash_suffix{};

  for (int i = 1; i <= n; ++i) {
    hash_prefix[i] = hash_prefix[i - 1] * kHashBase + v[i];
    hash_suffix[i] = hash_suffix[i - 1] * kHashBase + v[n - i + 1];
  }

  const int m = readInt();

  [[assume(m >= 1 && m <= 1000000)]];
  for (int i = 0; i < m; ++i) {
    int s_forward = readInt();
    int e_forward = readInt();
    int s_backward = n - e_forward + 1;
    int e_backward = n - s_forward + 1;

    unsigned long long hash_forward =
        hash_prefix[e_forward] -
        hash_prefix[s_forward - 1] * kHashPower[e_forward - s_forward + 1];
    unsigned long long hash_backward =
        hash_suffix[e_backward] -
        hash_suffix[s_backward - 1] * kHashPower[e_backward - s_backward + 1];
    writeChar(hash_forward == hash_backward ? '1' : '0');
    writeChar('\n');
  }

  return 0;
}