from sys import stdin
N = int(stdin.readline())

A = list(map(int, stdin.readline().split(' ')))

p = [0]
res = []
acc = 0
ma = 0
cur = 0
for _ in range(len(A)):
    res.append(ma + p[-1])
    acc += A[_]
    cur += acc
    ma = max(ma, acc)
    p.append(cur)

res.append(p[-1])
print(max(res))
