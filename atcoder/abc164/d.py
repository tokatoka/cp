from sys import stdin
from collections import defaultdict
S = stdin.readline().rstrip()

revS = S[::-1]
#print(revS)

MOD = 2019
a_sum = [0 for _ in range(len(S) + 1)]
power_of_ten = [0 for _ in range(len(S) + 1)]

power_of_ten[0] = 1
for i in range(1, len(power_of_ten)):
    power_of_ten[i] = power_of_ten[i - 1] * 10 % MOD
#print(power_of_ten)
for i in range(1, len(a_sum)):
    a_sum[i] = (a_sum[i - 1] + int(revS[i - 1]) * power_of_ten[i - 1]) % MOD
#print(a_sum)
res = 0
mp = defaultdict(int)
for i in range(len(a_sum)):
    res += mp[a_sum[i]]
    mp[a_sum[i]] += 1

print(res)