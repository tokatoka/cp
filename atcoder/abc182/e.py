from sys import stdin
from collections import deque
H,W,N,M = map(int, stdin.readline().split(' '))

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
brett = [[0 for _ in range(W)] for _ in range(H)]
lights = []
for _ in range(N):
    A,B = map(int, stdin.readline().split(' '))
    A-=1
    B-=1
    brett[A][B] = 1 #light
    lights.append((A,B))

for _ in range(M):
    C,D = map(int, stdin.readline().split(' '))
    C-=1
    D-=1
    brett[C][D] = 2 #block

for i in range(len(lights)):
    a,b = lights[i]
    for dir in range(4):
        x,y = a,b
        while True:
            x += dx[dir]
            y += dy[dir]
            if x >= 0 and x < H and y >= 0 and y < W and brett[x][y] in [0, 3]:
                brett[x][y] = 3
            else:
                break


res = 0
for r in range(H):
    for c in range(W):
        if brett[r][c] in [1, 3]:
            res += 1

print(res)