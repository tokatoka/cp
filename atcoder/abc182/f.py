from sys import stdin

N,X = map(int, stdin.readline().split(' '))
A = list(map(int, stdin.readline().split(' ')))
x = [0 for _ in range(N)]
for i in range(N - 1, -1, -1):
    x[i] = X//A[i]
    X %= A[i]
t = [0 for _ in range(N)]
for i in range(N - 1):
    t[i] = A[i + 1]//A[i]
t[N - 1] = 1e18

dp = [1, 0]
for i in range(N):
    p = [0, 0]
    dp,p = p, dp
    for j in range(2):
        for nj in range(2):
            #y == 0
            z = 0 + t[i] * nj - x[i] - j
            if z >= 0 and z < t[i]:
                dp[nj] += p[j]
            
            y = x[i] + 0 + j - t[i] * nj
            if y > 0 and y < t[i]:
                dp[nj] += p[j]
print(dp[0])