from sys import stdin
from collections import defaultdict
N = int(stdin.readline())

A = list(map(int, stdin.readline().split(' ')))

mp = defaultdict(list)
res = 0
for i in range(len(A)):
    mp[i + A[i]].append(i)
    res += len(mp[i - A[i]])
print(res)