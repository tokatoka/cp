from sys import stdin
from math import gcd
from functools import reduce
N = int(stdin.readline())
A = list(map(int, stdin.readline().split(' ')))

largest = max(A)
spf = [_ for _ in range(largest + 1)]
i = 2
while i * i <= largest:
    if spf[i] == i:
        for j in range(i * i, largest + 1, i):
            if spf[j] == j:
                spf[j] = i
    i += 1

pairwise = True
setwise = True


mp = [0 for _ in range(largest + 1)]
for a in A:
    factorize(a, mp)

if reduce(gcd, A) != 1:
    setwise = False

if pairwise:
    print("pairwise coprime")
elif setwise:
    print("setwise coprime")
else:
    print("not coprime")
