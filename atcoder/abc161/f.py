from sys import stdin

N = int(stdin.readline())

def divisors(n):
    ret = []
    for i in range(1, int(n ** 0.5 + 1)):
        if n % i == 0:
            ret.append(i)
            if i * i != n:
                ret.append(n // i)
    return ret

div1 = divisors(N)
div2 = set(divisors(N - 1))
for v in div1:
    if v == 1:
        continue
    m = N
    while m % v == 0:
        m = m // v
    if m % v == 1:
        div2 |= {v}
print(len(div2) - 1)