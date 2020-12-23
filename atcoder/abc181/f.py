from collections import defaultdict
from sys import stdin
from math import hypot


class UnionFind:
    def __init__(self, N):
        self.parent = [n for n in range(0, N)]
        self.size = [1] * N

    def find_root(self, x):
        if self.parent[x] == x:
            return x
        self.parent[x] = self.find_root(self.parent[x])
        return self.parent[x]

    def get_size(self, x):
        return self.size[self.find_root(x)]

    def unite(self, x, y):
        gx = self.find_root(x)
        gy = self.find_root(y)
        if gx == gy:
            return
        if self.size[gx] < self.size[gy]:
            self.parent[gx] = gy
            self.size[gy] += self.size[gx]
        else:
            self.parent[gy] = gx
            self.size[gx] += self.size[gy]


N = int(stdin.readline())
xy = []
for _ in range(N):
    x, y = map(int, stdin.readline().split(' '))
    xy.append((x, y))
S = N
T = N + 1
edge = []
for i in range(len(xy)):
    x, y = xy[i]
    edge.append((y + 100, i, S))
    edge.append((100 - y, i, T))
for i in range(len(xy)):
    for j in range(i + 1, len(xy)):
        x1, y1 = xy[i]
        x2, y2 = xy[j]
        edge.append((hypot(x2 - x1, y2 - y1), i, j))

edge.sort()
uf = UnionFind(N + 2)

for l, i, j in edge:
    uf.unite(i, j)
    if uf.find_root(S) == uf.find_root(T):
        print(l/2)
        exit()
