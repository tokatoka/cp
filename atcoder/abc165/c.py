from sys import stdin
import itertools
N,M,Q = map(int, stdin.readline().split(' '))
X = [list(map(int,stdin.readline().split(' '))) for _ in range(Q)]
nums = [x for x in range(1, M + 1)]
res = 0
for x in itertools.combinations_with_replacement(nums, N):
    score = 0
    for a,b,c,d in X:
        if x[b - 1] - x[a - 1] == c:
            score += d
    res = max(res, score)

print(res)