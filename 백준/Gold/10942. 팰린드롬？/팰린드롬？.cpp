#include <bits/stdc++.h>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////
/*
 * Author : jinhan814
 * Date : 2021-05-06
 * Source : https://blog.naver.com/jinhan814/222266396476
 * Description : FastIO implementation for cin, cout.
 */
constexpr int SZ = 1 << 20;

class INPUT {
 private:
  char read_buf[SZ];
  int read_idx, next_idx;
  bool __END_FLAG__, __GETLINE_FLAG__;

 public:
  explicit operator bool() { return !__END_FLAG__; }
  bool IsBlank(char c) { return c == ' ' || c == '\n'; }
  bool IsEnd(char c) { return c == '\0'; }
  char _ReadChar() {
    if (read_idx == next_idx) {
      next_idx = fread(read_buf, sizeof(char), SZ, stdin);
      if (next_idx == 0) return 0;
      read_idx = 0;
    }
    return read_buf[read_idx++];
  }
  char ReadChar() {
    char ret = _ReadChar();
    for (; IsBlank(ret); ret = _ReadChar());
    return ret;
  }
  template <typename T>
  T ReadInt() {
    T ret = 0;
    char cur = _ReadChar();
    bool flag = 0;
    for (; IsBlank(cur); cur = _ReadChar());
    if (cur == '-') flag = 1, cur = _ReadChar();
    for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar())
      ret = 10 * ret + (cur & 15);
    if (IsEnd(cur)) __END_FLAG__ = 1;
    return flag ? -ret : ret;
  }
  string ReadString() {
    string ret;
    char cur = _ReadChar();
    for (; IsBlank(cur); cur = _ReadChar());
    for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar()) ret.push_back(cur);
    if (IsEnd(cur)) __END_FLAG__ = 1;
    return ret;
  }
  double ReadDouble() {
    string ret = ReadString();
    return stod(ret);
  }
  string getline() {
    string ret;
    char cur = _ReadChar();
    for (; cur != '\n' && !IsEnd(cur); cur = _ReadChar()) ret.push_back(cur);
    if (__GETLINE_FLAG__) __END_FLAG__ = 1;
    if (IsEnd(cur)) __GETLINE_FLAG__ = 1;
    return ret;
  }
  friend INPUT& getline(INPUT& in, string& s) {
    s = in.getline();
    return in;
  }
} _in;

class OUTPUT {
 private:
  char write_buf[SZ];
  int write_idx;

 public:
  ~OUTPUT() { Flush(); }
  explicit operator bool() { return 1; }
  void Flush() {
    fwrite(write_buf, sizeof(char), write_idx, stdout);
    write_idx = 0;
  }
  void WriteChar(char c) {
    if (write_idx == SZ) Flush();
    write_buf[write_idx++] = c;
  }
  template <typename T>
  int GetSize(T n) {
    int ret = 1;
    for (n = n >= 0 ? n : -n; n >= 10; n /= 10) ret++;
    return ret;
  }
  template <typename T>
  void WriteInt(T n) {
    int sz = GetSize(n);
    if (write_idx + sz >= SZ) Flush();
    if (n < 0) write_buf[write_idx++] = '-', n = -n;
    for (int i = sz; i-- > 0; n /= 10) write_buf[write_idx + i] = n % 10 | 48;
    write_idx += sz;
  }
  void WriteString(string s) {
    for (auto& c : s) WriteChar(c);
  }
  void WriteDouble(double d) { WriteString(to_string(d)); }
} _out;

/* operators */
INPUT& operator>>(INPUT& in, char& i) {
  i = in.ReadChar();
  return in;
}
INPUT& operator>>(INPUT& in, string& i) {
  i = in.ReadString();
  return in;
}
template <typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
INPUT& operator>>(INPUT& in, T& i) {
  if constexpr (is_floating_point_v<T>)
    i = in.ReadDouble();
  else if constexpr (is_integral_v<T>)
    i = in.ReadInt<T>();
  return in;
}

OUTPUT& operator<<(OUTPUT& out, char i) {
  out.WriteChar(i);
  return out;
}
OUTPUT& operator<<(OUTPUT& out, string i) {
  out.WriteString(i);
  return out;
}
template <typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
OUTPUT& operator<<(OUTPUT& out, T i) {
  if constexpr (is_floating_point_v<T>)
    out.WriteDouble(i);
  else if constexpr (is_integral_v<T>)
    out.WriteInt<T>(i);
  return out;
}

/* macros */
#define fastio 1
#define cin _in
#define cout _out
#define istream INPUT
#define ostream OUTPUT
/////////////////////////////////////////////////////////////////////////////////////////////

int main() {
  mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<> dist(0x10203040, 0x50607080);
  uint64_t hash_base = dist(gen);

  int n;
  cin >> n;

  vector<int> v(n + 1);

  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
  }

  vector<uint64_t> hash_prefix(n + 2, 0);
  vector<uint64_t> hash_suffix(n + 2, 0);
  vector<uint64_t> hash_power(n + 2, 1);

  for (int i = 1; i <= n; ++i) {
    hash_power[i] = hash_power[i - 1] * hash_base;
    hash_prefix[i] = hash_prefix[i - 1] * hash_base + v[i];
    hash_suffix[i] = hash_suffix[i - 1] * hash_base + v[n - i + 1];
  }

  int m;
  cin >> m;

  for (int i = 0; i < m; ++i) {
    int s_forward, e_forward;
    cin >> s_forward >> e_forward;
    int s_backward = n - e_forward + 1;
    int e_backward = n - s_forward + 1;

    uint64_t hash_forward =
        hash_prefix[e_forward] -
        hash_prefix[s_forward - 1] * hash_power[e_forward - s_forward + 1];
    uint64_t hash_backward =
        hash_suffix[e_backward] -
        hash_suffix[s_backward - 1] * hash_power[e_backward - s_backward + 1];
    cout << (hash_forward == hash_backward) << "\n";
  }

  return 0;
}