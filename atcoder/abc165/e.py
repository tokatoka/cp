N, M = map(int, input().split(' '))
N = 2 * M + 1
for i in range(0, M//2):
    print(i + 1, M - i)
for i in range(0, M - M//2):
    print(M + 1 + i, N - i)