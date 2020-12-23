from sys import stdin, setrecursionlimit
setrecursionlimit(1000000)
N, A, B, C = map(int, stdin.readline().split(' '))
mp = dict()
S = []
for _ in range(N):
    S.append(stdin.readline().rstrip())
ans = []
def dfs(cur, a, b, c):
    if cur == N:
        return True
    if S[cur] == "AB":
        if a == 0 and b == 0:
            return False
        if a > 0 and dfs(cur + 1, a - 1, b + 1, c):
            ans.append('B')
            return True
        if b > 0 and dfs(cur + 1, a + 1, b - 1, c):
            ans.append('A')
            return True
        return False     

    if S[cur] == "BC":
        if b == 0 and c == 0:
            return False
        if b > 0 and dfs(cur + 1, a , b - 1, c + 1):
            ans.append('C')
            return True
        if c > 0 and dfs(cur + 1, a, b + 1, c - 1):
            ans.append('B')
            return True
        return False

    if S[cur] == "AC":
        if a == 0 and c == 0:
            return False
        if a > 0 and dfs(cur + 1, a - 1, b, c + 1):
            ans.append('C')
            return True
        if c > 0 and dfs(cur + 1, a + 1, b, c - 1):
            ans.append('A')
            return True
        return False     

dfs(0, A, B, C)
if len(ans) == 0:
    print("No")
else:
    print("Yes")
    for _ in ans[::-1]:
        print(_)