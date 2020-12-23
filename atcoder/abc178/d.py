import sys
sys.setrecursionlimit(1000000)
N = int(sys.stdin.readline())

mp = [-1 for _ in range(2000 + 10)]
mp[0] = 0
mp[1] = 0
mp[2] = 0
mp[3] = 1

MOD = pow(10, 9) + 7


def f(N):
    if mp[N] >= 0:
        return mp[N]
    v = (f(N - 1) + f(N - 3)) % MOD
    mp[N] = v
    return v


'''
f(N) = f(N - 3) + f(N - 4) + .... + f(1)
f(N) = f(N - 1) + f(N - 3)
'''

print(f(N))
