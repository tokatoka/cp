from sys import stdin
import bisect
N, M = map(int, stdin.readline().split(' '))
H = list(map(int, stdin.readline().split(' ')))
W = list(map(int, stdin.readline().split(' ')))

H.sort()
left = [0 for _ in range(N + 1)]
right = [0 for _ in range(N + 1)]
for i in range(2, N, 2):
    left[i] = left[i - 2] + H[i - 1] - H[i - 2]
    right[i] = right[i - 2] + H[N - i + 1] - H[N - i]

res = float('inf')
for w in W:
    i = bisect.bisect_left(H, w)
    if i % 2 == 0:
        res = min(res, left[i] + right[N - i - 1] + H[i] - w)
    else:
        res = min(res, left[i - 1] + right[N - i] + w - H[i - 1])

print(res)