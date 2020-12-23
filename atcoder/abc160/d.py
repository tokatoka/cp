from sys import stdin
from collections import Counter, deque
N,X,Y = map(int, stdin.readline().split(' '))
X -= 1
Y -= 1
G = [[] for _ in range(N)]
for i in range(N-1):
    G[i].append(i + 1)
    G[i+1].append(i)

G[X].append(Y)
G[Y].append(X)

mp = [0 for _ in range(N)]
for _ in range(N):
    q = deque()
    dist = [float('inf') for _ in range(N)]
    q.append(_)
    dist[_] = 0
    while len(q):
        top = q.pop()
        for ne in G[top]:
            if dist[ne] > dist[top] + 1 and ne != _:
                q.append(ne)
                dist[ne] = dist[top] + 1
    for k, v in Counter(dist).most_common():
        mp[k] += v

mp = [item // 2 for item in mp[1:]]
for _ in mp:
    print(_)