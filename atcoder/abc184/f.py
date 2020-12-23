from sys import stdin
import bisect

N,T = map(int, stdin.readline().split(' '))
a = list(map(int, stdin.readline().split(' ')))

lower = a[:len(a)//2]
higher = a[len(a)//2:]

l1 = len(a)//2
l2 = len(a) - l1

ma = 0
kandidat1 = []
for i in range(1 << l1):
    time = 0
    for j in range(l1):
        if i & (1 << j):
            time += lower[j]
    if time > T:
        continue
    kandidat1.append(time)
kandidat1.sort()

for i in range(1 << l2):
    time = 0
    for j in range(l2):
        if i & (1 << j):
            time += higher[j]
    if time > T:
        continue
    idx = bisect.bisect_right(kandidat1, T - time)
    ma = max(ma, time + kandidat1[idx - 1])

print(ma)

