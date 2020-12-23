from sys import stdin
N, X, M = map(int, stdin.readline().split(' '))

mp = [-1 for _ in range(M + 1)]
stack = []
hist = []
res = 0
for i in range(N):
    if mp[X] != -1:
        prev = mp[X]
        for j in range(prev, i):
            stack.append(hist[j])
        break

    mp[X] = i
    hist.append(X)
    res += X
    X = (X * X) % M

N -= len(hist)

if N == 0:
    print(res)
    exit()

asum = [0 for _ in range(len(stack) + 1)]
for i in range(0, len(stack)):
    asum[i + 1] = asum[i] + stack[i]

q = N // len(stack)
r = N % len(stack)

res += q * asum[len(stack)] + asum[r]
print(res)
