from sys import stdin
h,w = map(int, stdin.readline().split(' '))

S = []
for _ in range(h):
    S.append(list(stdin.readline().rstrip()))

dp = [[(0,0,0,0) for _ in range(w)] for __ in range(h)]

dp[0][0] = (1,1,1,1) #accumulated sum along row, col, diagonal line, dp value
MOD = pow(10,9) + 7

for c in range(1, w):
    if S[0][c] == '#':
        continue
    else:
        v = dp[0][c - 1][0]
        dp[0][c] = ((v * 2)% MOD, v, v, v)

for r in range(1, h):
    if S[r][0] == '#':
        continue
    else:
        v = dp[r - 1][0][1]
        dp[r][0] = (v, (v * 2)%MOD, v, v)

for r in range(1, h):
    for c in range(1, w):
        if S[r][c] == '#':
            continue
        else:
            v = dp[r][c - 1][0] + dp[r - 1][c][1] + dp[r - 1][c - 1][2]
            v = v % MOD
            dp[r][c] = ((dp[r][c - 1][0] + v) % MOD,(dp[r - 1][c][1] + v) % MOD,(dp[r - 1][c - 1][2] + v) % MOD,v)
print(dp[r][c][3] % MOD)
