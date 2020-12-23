from sys import stdin
X, Y, A, B = map(int, stdin.readline().split(' '))

res = 0
while (A - 1) * X < B and A * X < Y:
    X = A * X
    res += 1
res += (Y - 1 - X) // B

print(res)
