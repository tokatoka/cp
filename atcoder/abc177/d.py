
from sys import stdin


class UnionFind:
    def __init__(self, N):
        self._parent = [n for n in range(0, N)]
        self._size = [1] * N

    def find_root(self, x):
        if self._parent[x] == x:
            return x
        self._parent[x] = self.find_root(self._parent[x])
        return self._parent[x]

    def is_same_group(self, x, y):
        return self.find_root(x) == self.find_root(y)

    def unite(self, x, y):
        gx = self.find_root(x)
        gy = self.find_root(y)
        if gx == gy:
            return
        if self._size[gx] < self._size[gy]:
            self._parent[gx] = gy
            self._size[gy] += self._size[gx]
        else:
            self._parent[gy] = gx
            self._size[gx] += self._size[gy]

    def calc_group_num(self):
        N = len(self._parent)
        ans = 0
        for i in range(N):
            if self.find_root(i) == i:
                ans += 1
        return ans


N, M = map(int, stdin.readline().split(' '))
uf = UnionFind(N)
for _ in range(M):
    a, b = map(int, stdin.readline().split(' '))
    a -= 1
    b -= 1
    uf.unite(a, b)

print(max(uf._size))
