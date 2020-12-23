from sys import stdin

N, K = map(int ,stdin.readline().split(' '))

A = [_ for _ in range(N + 1)]
a_sum_l = [0 for _ in range(N + 2)]
for i in range(1, N + 2):
    a_sum_l[i] = a_sum_l[i - 1] + A[i - 1]
res = 0
MOD = pow(10, 9) + 7
total = sum(A)
for k in range(K, N + 1):
    #sum form k = K to k = N
    res += ((total - a_sum_l[N - k + 1] - a_sum_l[k]) + 1) % MOD
    
print((res + 1) % MOD)