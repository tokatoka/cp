from sys import stdin
import bisect
N, M, K = map(int, stdin.readline().split(' '))
A = list(map(int, stdin.readline().split(' ')))
B = list(map(int, stdin.readline().split(' ')))

a_sumA = [0]
a_sumB = [0]
for _ in range(N):
    a_sumA.append(a_sumA[-1] + A[_])
for _ in range(M):
    a_sumB.append(a_sumB[-1] + B[_])

res = 0
#print(a_sumA, a_sumB)
for i in range(N + 1):
    remaining = K - a_sumA[i]
    if remaining < 0:
        break
    #print(i, remaining, bisect.bisect_right(a_sumB, remaining))
    res = max(res, i + bisect.bisect_right(a_sumB, remaining) - 1)
print(res)
