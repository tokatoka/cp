from sys import stdin
from typing import List


class Fenwick:
    def __init__(self, nums: List[int]):
        self.n = len(nums)
        self.data = [0] * (self.n + 1)
        self.nums = nums
        for i in range(len(nums)):
            self.add(i + 1, nums[i])

    def add(self, x, val):
        while x <= self.n:
            self.data[x] += val
            x += x & (-x)

    def update(self, i: int, val: int) -> None:
        self.add(i + 1, val - self.nums[i])
        self.nums[i] = val

    def sum(self, x):
        res = 0
        while x > 0:
            res += self.data[x]
            x -= x & (-x)
        return res

    def sumRange(self, i: int, j: int) -> int:
        return self.sum(j + 1)-self.sum(i)


N, Q = map(int, stdin.readline().split(' '))
c = list(map(int, stdin.readline().split(' ')))

lrs = []
last_seen = [-1 for _ in range(N + 1)]
bit = Fenwick([0 for _ in range(len(c))])
orig = []
for q in range(Q):
    l, r = map(int, stdin.readline().split(' '))
    l -= 1
    r -= 1
    lrs.append((q, l, r))
lrs.sort(key=lambda x: x[2])
res = [0 for _ in range(Q)]
curr = 0
for i in range(len(lrs)):
    while curr < N and curr <= lrs[i][2]:
        if last_seen[c[curr]] < 0:
            bit.update(curr, 1)
        else:
            bit.update(curr, 1)
            bit.update(last_seen[c[curr]], 0)
        last_seen[c[curr]] = curr

        curr += 1

        # at this point curr = lrs[1] and we are ready to answer the query
    res[lrs[i][0]] = (bit.sumRange(lrs[i][1], lrs[i][2]))
for _ in res:
    print(_)
