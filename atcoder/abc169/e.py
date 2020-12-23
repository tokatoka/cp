from sys import stdin

N = int(stdin.readline())
A,B=[],[]
for _ in range(N):
    a,b = map(int, stdin.readline().split(' '))
    A.append(a)
    B.append(b)

A.sort()
B.sort()

if (N & 1):
    m = A[len(A)//2]
    M = B[len(B)//2]
    print((M - m) + 1)

else:
    m = (A[len(A)//2] + A[len(A)//2 - 1])/2
    M = (B[len(B)//2] + B[len(B)//2 - 1])/2
    print(int((M - m) * 2 + 1))