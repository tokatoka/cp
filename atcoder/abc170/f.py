from sys import stdin
from collections import deque
H, W, K = map(int, stdin.readline().split(' '))
x1,y1,x2,y2 = map(int, stdin.readline().split(' '))
x1 -= 1
y1 -= 1
x2 -= 1
y2 -= 1
pond = []
for _ in range(H):
    r = [x for x in stdin.readline().rstrip()]
    pond.append(r)

q = deque([(x1, y1)])
dist = [[float('inf') for _ in range(W)] for _ in range(H)]
dist[x1][y1] = 0


dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
while q:
    cx, cy = q.popleft()
    for dir in range(4):
        for k in range(1, K + 1):
            nx, ny = cx + dx[dir] * k, cy + dy[dir] * k
            #print("cx, cy nx, ny, dist", cx, cy, nx, ny, dist)
            if nx >= 0 and nx < H and ny >= 0 and ny < W and pond[nx][ny] == '.' and dist[nx][ny] > dist[cx][cy]:
                if dist[nx][ny] == dist[cx][cy] + 1:
                    continue
                dist[nx][ny] = dist[cx][cy] + 1
                q.append((nx, ny))
                #print('update')
            else:
                #print("break")
                break

if dist[x2][y2] == float('inf'):
    print(-1)
else:
    print(dist[x2][y2])