import sys
import math


def main():
    n = int(sys.stdin.readline())

    dp = [0] * (n + 1)
    dp[0] = 1

    for m in range(1, n + 1):
        sum = 0
        for k in range(1, m + 1):
            t = math.comb(m, k) * pow(2, k * (m - k)) * dp[m - k]
            if (k & 1) == 0:
                t = -t
            sum += t
        dp[m] = sum

    print(dp[n])


if __name__ == "__main__":
    main()
