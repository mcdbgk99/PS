#pragma GCC optimize("O3,unroll-loops")
#include <sys/mman.h>
#include <unistd.h>
using namespace std;

namespace FastIO {
char* input_ptr;
__attribute__((constructor)) void init() {
  input_ptr = (char*)mmap(0, 1 << 23, PROT_READ, MAP_PRIVATE, 0, 0);
}

inline void scan(int& x) {
  asm volatile(
      "xor %%eax, %%eax\n"  // x = 0
      "mov %1, %%rsi\n"     // 64-bit 포인터 로드
      // 숫자가 아닌 문자 건너뛰기
      "1:\n"
      "movb (%%rsi), %%cl\n"
      "cmp $0x30, %%cl\n"
      "jge 2f\n"
      "inc %%rsi\n"
      "jmp 1b\n"
      // 첫 번째 숫자 처리
      "2:\n"
      "movzbl (%%rsi), %%ecx\n"
      "inc %%rsi\n"
      "sub $0x30, %%ecx\n"
      "add %%ecx, %%eax\n"
      // 나머지 숫자 처리
      "3:\n"
      "movzbl (%%rsi), %%ecx\n"
      "cmp $0x30, %%ecx\n"
      "jl 4f\n"
      "inc %%rsi\n"
      "sub $0x30, %%ecx\n"
      "imul $10, %%eax\n"
      "add %%ecx, %%eax\n"
      "jmp 3b\n"
      "4:\n"
      "mov %%rsi, %1\n"  // 포인터 업데이트
      "mov %%eax, %0\n"  // 결과 저장
      : "=m"(x), "+m"(input_ptr)
      :
      : "rax", "rcx", "rsi", "memory");
}
}  // namespace FastIO

constexpr int MAX_N = 1000001;
alignas(64) int points[MAX_N];

inline int Find(int x) {
  asm volatile(
      "mov %0, %%eax\n"
      "1:\n"
      "mov (points)(,%%eax,4), %%ebx\n"
      "test %%ebx, %%ebx\n"
      "js 2f\n"
      "mov (points)(,%%ebx,4), %%ecx\n"
      "test %%ecx, %%ecx\n"
      "js 3f\n"
      "mov %%ecx, (points)(,%%eax,4)\n"
      "3:\n"
      "mov %%ebx, %%eax\n"
      "jmp 1b\n"
      "2:\n"
      : "=a"(x)
      : "0"(x)
      : "ebx", "ecx", "memory");
  return x;
}

inline void Union(int a, int b) {
  asm volatile(
      "mov %0, %%eax\n"
      "mov %1, %%ebx\n"
      "mov (points)(,%%eax,4), %%ecx\n"
      "mov (points)(,%%ebx,4), %%edx\n"
      "cmp %%ecx, %%edx\n"
      "jle 1f\n"
      "xchg %%eax, %%ebx\n"
      "1:\n"
      "add %%edx, %%ecx\n"
      "mov %%ecx, (points)(,%%eax,4)\n"
      "mov %%eax, (points)(,%%ebx,4)\n"
      :
      : "r"(a), "r"(b)
      : "eax", "ebx", "ecx", "edx", "memory");
}

int main() {
  int n, m;
  FastIO::scan(n);
  FastIO::scan(m);

  for (int i = 0; i <= n; ++i) {
    points[i] = -1;
  }

  for (int i = 1; i <= m; ++i) {
    int a, b;
    FastIO::scan(a);
    FastIO::scan(b);
    a = Find(a);
    b = Find(b);

    if (a == b) {
      char num[10];
      char* p = num + 9;
      do *--p = '0' + i % 10;
      while (i /= 10);
      write(1, p, num + 9 - p);
      return 0;
    }
    Union(a, b);
  }

  write(1, "0", 1);
  return 0;
}