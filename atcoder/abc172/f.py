from sys import stdin
from operator import xor
from functools import reduce
N = int(input())
A = list(map(int, stdin.readline().split(' ')))


a = A[0]
b = A[1]
if N >= 3:
    x = reduce(xor, A[2:])
else:
    x = 0
s = a + b

K = 43
dp = [[[-1 for _ in range(2)] for _ in range(2)] for _ in range(K)]
dp[0][0][0] = 0
v = 1

for i in range(K - 1):
    cx = x & 1
    cs = s & 1
    ca = a & 1
    for j in range(2):
        for k in range(2):
            if dp[i][j][k] == -1:
                continue
            for na in range(2):
                for nb in range(2):
                    ni = i + 1
                    nj = 0
                    nk = k
                    if (na ^ nb) != cx:
                        continue
                    ns = na + nb + j
                    if ns % 2 != cs:
                        continue
                    if ns >= 2:
                        nj = 1
                    if ca < na:
                        nk = 1
                    elif ca == na:
                        nk = k
                    else:
                        nk = 0
                    dp[ni][nj][nk] = max(
                        dp[ni][nj][nk], dp[i][j][k] | (v * na))
    x = x >> 1
    s = s >> 1
    a = a >> 1
    v = v << 1

a = dp[K - 1][0][0]
if a == -1 or a == 0:
    print(-1)
    exit()
print(A[0] - a)
