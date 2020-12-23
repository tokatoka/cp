from collections import defaultdict
class UnionFind:
    def __init__(self,N,C):
        self.parent = [n for n in range(0, N)]
        self.size = [1] * N
        self.map = [defaultdict(int) for __ in range(N)]
        for _ in range(N):
            self.map[_][C[_] - 1] = 1
    def find_root(self,x):
        if self.parent[x] == x:
             return x
        self.parent[x] = self.find_root(self.parent[x])
        return self.parent[x]

    def get_size(self,x):
        return self.size[self.find_root(x)]
    def unite(self,x,y):
        gx = self.find_root(x)
        gy = self.find_root(y)
        if gx == gy:
            return
        if self.size[gx] < self.size[gy]:
            self.parent[gx] = gy
            self.size[gy] += self.size[gx]
            for key, value in self.map[gx].items():
                self.map[gy][key] += value
        else:
            self.parent[gy] = gx
            self.size[gx] += self.size[gy]
            for key, value in self.map[gy].items():
                self.map[gx][key] += value


from sys import stdin
N, Q = map(int, stdin.readline().split(' '))

C = list(map(int, stdin.readline().split(' ')))
uf = UnionFind(N, C)
for _ in range(Q):
    q, ax, by = map(int, stdin.readline().split(' '))
    ax -= 1
    by -= 1

    if q == 1:
        uf.unite(ax, by)
    else:
        g = uf.find_root(ax)
        print(uf.map[g][by])