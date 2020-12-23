import sys

N = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split(' ')))

dp = [0 for _ in range(max(A) + 1)]

for a in A:
    n = a
    while n <= max(A):
        dp[n] += 1
        n = n + a
res = 0
for a in A:
    if dp[a] == 1:
        res += 1

print(res)
