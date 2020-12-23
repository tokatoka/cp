from collections import defaultdict
from functools import lru_cache
N = int(input())
spf = [_ for _ in range(N + 1)]
i = 2
while i * i <= N:
    if spf[i] == i:
        for j in range(i * i, N + 1, i):
            if spf[j] == j:
                spf[j] = i
    i += 1


@lru_cache(maxsize=None)
def factorize(n):
    m = defaultdict(int)
    while n != 1:
        m[spf[n]] += 1
        n = n // spf[n]
    res = 1
    for i in m:
        res = res * (m[i] + 1)
    return res


res = 0
for i in range(1, N + 1):
    res += i * factorize(i)
print(res)
