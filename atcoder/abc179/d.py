from sys import stdin
N, K = map(int, stdin.readline().split(' '))
lr = []
for _ in range(K):
    l, r = stdin.readline().split(' ')
    lr.append((int(l), int(r)))
MOD = 998244353
dp = [0 for _ in range(N)]
acc_dp = [0 for _ in range(N + 1)]
dp[0] = 1
acc_dp[1] = 1  # acc_dp[n] = dp[0] + ... + dp[n - 1]
for i in range(1, N):
    for a, b in lr:
        l = max(0, i - b)
        r = max(0, i - a + 1)
        dp[i] = (acc_dp[r] - acc_dp[l] + dp[i]) % MOD
    acc_dp[i + 1] = (acc_dp[i] + dp[i]) % MOD

print(dp[N - 1])
