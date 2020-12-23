from sys import stdin
from collections import Counter
H, W, M = map(int, stdin.readline().split(' '))
hws = [tuple(map(int, stdin.readline().split())) for _ in range(M)]
hwset = set()

mp = dict()
rows = [0 for _ in range(H + 1)]
cols = [0 for _ in range(W + 1)]
for h, w in hws:
    rows[h] += 1
    cols[w] += 1
    hwset.add((h, w))
rmax = max(rows)
cmax = max(cols)

max_rows = []
max_cols = []
for i in range(H + 1):
    if rows[i] == rmax:
        max_rows.append(i)
for i in range(W + 1):
    if cols[i] == cmax:
        max_cols.append(i)
if len(max_rows) * len(max_cols) > M:
    print(rmax + cmax)
    exit()

for r in max_rows:
    for c in max_cols:
        if (r, c) not in hwset:
            print(rmax + cmax)
            exit()
print(rmax + cmax - 1)
