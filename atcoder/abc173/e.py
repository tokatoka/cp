import sys
import operator
from functools import reduce
from decimal import *
MOD = pow(10, 9) + 7


def f(lst):
    sign = 1
    res = 1
    for i in lst:
        if i[1] < 0:
            sign *= -1
            res = (res * (i[0] % MOD)) % MOD
        else:
            res = (res * (i[0] % MOD)) % MOD
    res = sign * res
    if res < 0:
        res = res + MOD
    res = res % MOD
    return res, sign


N, K = map(int, sys.stdin.readline().split(' '))

A = list(map(int, sys.stdin.readline().split(' ')))

kandidaten = [(abs(x), x) for x in A]
kandidaten.sort(reverse=True)
used = kandidaten[:K]
unused = kandidaten[K:]
cur, sign = f(used)
if sign > 0:
    print(cur)
    exit()

pos_used = [x for x in used if x[1] > 0]
neg_used = [x for x in used if x[1] < 0]
pos_unused = [x for x in unused if x[1] > 0]
neg_unused = [x for x in unused if x[1] < 0]
# case 1 pop one negative value from neg_used, append one positive value from pos_unused

c1, c2 = -1, -1
f1, f2 = False, False
if len(neg_used) and len(pos_unused):
    c1, _ = f(pos_used + neg_used[:-1] + [pos_unused[0]])
    f1 = True
# case 2 pop one positive value from pos_used, append one negative value from neg_unused
if len(pos_used) and len(neg_unused):
    c2, _ = f(pos_used[:-1] + neg_used + [neg_unused[0]])
    f2 = True

if f1 or f2:
    if not f1:
        cur = c2
    elif not f2:
        cur = c1
    else:
        if abs(Decimal(pos_unused[0][1]) / Decimal(neg_used[-1][1])) >= abs(Decimal(neg_unused[0][1]) / Decimal(pos_used[-1][1])):
            cur = c1
        else:
            cur = c2
    cur = cur % MOD
    cur += MOD
    print(cur % MOD)
    exit()
else:
    kandidaten = kandidaten[::-1]
    used = kandidaten[:K]
    cur, _ = f(used)
    print(cur)
    exit()
