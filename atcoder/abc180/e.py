from sys import stdin
from collections import defaultdict
N = int(stdin.readline())

X, Y, Z = [], [], []
for _ in range(N):
    x, y, z = map(int, stdin.readline().split(' '))
    X.append(x)
    Y.append(y)
    Z.append(z)

dp = [[float('inf') for _ in range(N)] for _ in range(1 << N)]


def dist(s, t): return abs(X[t] - X[s]) + \
    abs(Y[t] - Y[s]) + max(0, Z[t] - Z[s])


dp[1 << 0][0] = 0
for i in range(1, 1 << N):
    for j in range(N):
        for k in range(N):
            if i & (1 << k):
                continue
            else:
                dp[i | (1 << k)][k] = min(
                    dp[i | (1 << k)][k], dp[i][j] + dist(j, k))

res = float('inf')
for i in range(N):
    res = min(res, dp[(1 << N) - 1][i] + dist(i, 0))

print(res)
