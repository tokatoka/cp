import sys
N, Q = map(int, sys.stdin.readline().split(' '))


class SegTree:
    def __init__(self, nums):
        self.n = len(nums)
        length = 2 * self.n
        self.e = 1 << 30  # unit
        self.f = min  # func
        self.tree = [self.e] * length
        for i in range(self.n):  # init
            self.tree[self.n + i] = nums[i]
        for i in range(self.n - 1, 0, -1):  # build
            self.tree[i] = self.f(self.tree[i << 1], self.tree[i << 1 | 1])

    def update(self, i: int, val: int):
        self.tree[i + self.n] = self.f(val, self.tree[i + self.n])
        i = i + self.n
        idx = i
        while idx > 1:
            self.tree[idx >> 1] = self.f(self.tree[idx], self.tree[idx ^ 1])
            idx = idx >> 1

    def minRange(self, i: int, j: int):
        minimum = self.e
        i += self.n
        j += self.n
        while i < j:
            if (i & 1):
                minimum = self.f(minimum, self.tree[i])
                i += 1
            if (j & 1):
                j -= 1
                minimum = self.f(minimum, self.tree[j])
            i = i >> 1
            j = j >> 1
        return minimum


stH = SegTree([N - 1] * N)
stW = SegTree([N - 1] * N)
query = [tuple(map(int, sys.stdin.readline().split())) for _ in range(Q)]
res = 0
for t, x in query:
    x -= 1
    if t == 1:
        stA, stB = stW, stH
    else:
        stA, stB = stH, stW
    a = stA.minRange(x, N - 1 + 1)
    res += max(0, a - 1)
    stB.update(a, x)

print(pow(N - 2, 2) - res)
