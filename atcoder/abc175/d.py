from sys import stdin
N, K = map(int, stdin.readline().split(' '))
P = [int(x) - 1 for x in stdin.readline().split(' ')]
C = list(map(int, stdin.readline().split(' ')))

if all([x < 0 for x in C]):
    print(max(C))
    exit()
res = float('-inf')
ma = float('-inf')
for i in range(N):
    curr = i
    loop = []
    summe = 0
    while 1:
        curr = P[curr]
        summe += C[curr]
        loop.append(C[curr])
        if curr == i:
            break
    sofar = 0
    for _ in range(len(loop)):
        sofar += loop[_]
        if _ + 1 > K:
            break
        if summe > 0:
            cnt = (K - _ - 1) // len(loop)
            res = max(res, sofar + summe * cnt)
        res = max(res, sofar)

print(res)
