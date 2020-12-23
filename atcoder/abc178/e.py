import sys
import math
N = int(sys.stdin.readline())

pts1 = []
pts2 = []
for _ in range(N):
    x, y = map(int, sys.stdin.readline().split(' '))
    pts1.append((x+y, x, y))
    pts2.append((x-y, x, y))

pts1.sort()
pts2.sort()
print(max(abs(pts1[N - 1][1] - pts1[0][1]) + abs(pts1[N - 1][2] - pts1[0][2]),
          abs(pts2[N - 1][1] - pts2[0][1]) + abs(pts2[N - 1][2] - pts2[0][2])))
