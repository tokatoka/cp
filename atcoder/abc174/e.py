from sys import stdin
from math import ceil
N, K = map(int, stdin.readline().split(' '))
A = list(map(int, stdin.readline().split(' ')))


def isok(v):  # can we cut the logs so that the largest log has the lengh of v
    cnt = 0
    for _ in range(N):
        cnt += ceil(A[_]/v) - 1
    return cnt <= K


ok = pow(10, 9) + 1
ng = 0
while ok - ng > 1:
    mid = (ok + ng) >> 1
    if isok(mid):
        ok = mid
    else:
        ng = mid
print(ok)
