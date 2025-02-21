from collections import deque
import sys


def main():
  readline = sys.stdin.readline

  max_n = 100
  v = [0] * (max_n + 1)
  visited = [0] * (max_n + 1)

  n, m = map(int, readline().split())

  for _ in range(n + m):
    x, y = map(int, readline().split())
    v[x] = y

  dq = deque()
  dq.append((1, 0))
  result = 0

  while dq:
    now_num, now_step = dq.popleft()

    if now_num == max_n:
      result = now_step
      break

    for i in range(1, 7):
      new_num = now_num + i

      if new_num > max_n:
        continue

      if v[new_num] != 0:
        new_num = v[new_num]

      if visited[new_num] != 0 and visited[new_num] <= now_step + 1:
        continue

      visited[new_num] = now_step + 1
      dq.append((new_num, now_step + 1))

  print(result)


if __name__ == "__main__":
  main()
