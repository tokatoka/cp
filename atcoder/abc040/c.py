from sys import stdin
N = int(stdin.readline())
a = list(map(int, stdin.readline().split()))
dp = [float('inf') for _ in range(N + 1)]

dp[1] = 0
dp[2] = abs(a[1] - a[0])

for i in range(3, N+1):
    dp[i] = min(dp[i], dp[i - 1] + abs(a[i - 1] - a[i - 2]), dp[i - 2] + abs(a[i - 1] - a[i - 3]))

print(dp[N])