from sys import stdin

N = int(stdin.readline())

n_v = 0
for i in range(1, N + 1):
    n_v += i * (N - (i - 1))


n_e = 0
for _ in range(N - 1):
    va, vb = map(int, stdin.readline().split(' '))
    if va > vb:
        va, vb = vb, va
    n_e += va * (N - (vb - 1))

print(n_v - n_e)
