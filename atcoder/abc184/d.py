a,b,c = map(int,input().split())

dp = [[[-1 for _ in range(101)] for _ in range(101)] for _ in range(101)]
dp[100][100][100] = 0
def e(a,b,c):
    if a == 100 or b == 100 or c == 100:
        dp[a][b][c] = 0
        return 0
    if dp[a][b][c] > 0:
        return dp[a][b][c]
    else:
        res = ((e(a+1,b,c) + 1) * a / (a + b + c)) + ((e(a,b+1,c) + 1) * b / (a + b + c)) + ((e(a,b,c+1) + 1)* c/ (a + b + c))
        dp[a][b][c] = res
        return res

print(e(a,b,c))