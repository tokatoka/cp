import sys
from collections import defaultdict
from numba import jit


@jit
def main():
    R, C, K = map(int, sys.stdin.readline().split(' '))
    mp = [[0 for _ in range(C)] for _ in range(R)]
    for _ in range(K):
        r, c, v = map(int, sys.stdin.readline().split(' '))
        r -= 1
        c -= 1
        mp[r][c] = v

    dp = [[[-1 for _ in range(4)] for _ in range(C)] for _ in range(R)]

    dp[0][0][0] = 0
    for r in range(R):
        for c in range(C):
            for k in range(4):
                if dp[r][c][k] < 0:
                    continue
                if c + 1 < C:
                    dp[r][c + 1][k] = max(dp[r][c + 1][k], dp[r][c][k])
                    # we are gonna take the item at (r, c) and move to right
                    if k < 3 and mp[r][c] > 0:
                        dp[r][c + 1][k + 1] = max(dp[r][c + 1]
                                                  [k + 1], dp[r][c][k] + mp[r][c])
                if r + 1 < R:
                    dp[r + 1][c][0] = max(dp[r + 1][c][0], dp[r][c][k])
                    if k < 3 and mp[r][c] > 0:
                        dp[r + 1][c][0] = max(dp[r + 1][c][0],
                                              dp[r][c][k] + mp[r][c])
    for _ in range(3):
        dp[R - 1][C - 1][_] += mp[R - 1][C - 1]

    return max(dp[R - 1][C - 1])


print(main())
