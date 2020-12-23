from sys import stdin
from collections import deque
N, M = map(int, stdin.readline().split(' '))
G = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, stdin.readline().split(' '))
    a -= 1
    b -= 1
    G[a].append(b)
    G[b].append(a)

q = deque([])
q.append(0)

pa = [-1 for _ in range(N)]
pa[0] = 0
cur = 1
while q:
    top = q.popleft()
    for ne in G[top]:
        if pa[ne] < 0:
            pa[ne] = top
            q.append(ne)
if any([x < 0 for x in pa[1:]]):
    print("No")
else:
    print("Yes")
    print("\n".join([str(x + 1) for x in pa[1:]]))
