import sys
n = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split(' ')))
B = list(map(int, sys.stdin.readline().split(' ')))

mp = [0 for _ in range(n + 1)]
for i in A:
    mp[i] += 1
for i in B:
    mp[i] += 1
for i in range(0, n + 1):
    if mp[i] > n:
        print("No")
        exit()
C = B[::-1]
print("Yes")

same_x = 0
for i in range(n):
    if A[i] == C[i]:
        same_x = A[i]
        break

chg, same = [], []
for i in range(n):
    if A[i] == C[i]:
        same.append(i)
    elif A[i] != same_x and C[i] != same_x:
        chg.append(i)

while same:
    s, c = same.pop(), chg.pop()
    C[s], C[c] = C[c], C[s]
print(*C)
