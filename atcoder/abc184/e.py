from sys import stdin
from collections import defaultdict,deque
H,W = map(int,stdin.readline().split())

dx = [-1,0,1,0]
dy = [0,-1,0,1]
board = []
mp = [[] for _ in range(26)]
board = list(input() for _ in range(H))
sx,sy,tx,ty = 0,0,0,0
for h in range(H):
    for w in range(W):
        if board[h][w].islower():
            mp[ord(board[h][w]) - ord('a')].append((h,w))
        elif board[h][w] == 'S':
            sx,sy = h,w
        elif board[h][w] == 'G':
            tx,ty = h,w

dist = [[float('inf') for _ in range(W)] for _ in range(H)]
dist[sx][sy] = 0
q = deque()
q.append((sx,sy))

while len(q):
    x,y = q.popleft()
    if x == tx and y == ty:
        break
    for di in range(4):
        nx,ny = x + dx[di], y+dy[di]
        if nx < 0 or nx >= H or ny < 0 or ny >= W or board[nx][ny] == '#':
            continue
        if dist[nx][ny] == float('inf'):
            dist[nx][ny] = dist[x][y] + 1
            q.append((nx,ny))
    if board[x][y].islower():
        ch = ord(board[x][y]) - ord('a')
        for nx,ny in mp[ch]:
            if dist[nx][ny] == float('inf'):
                dist[nx][ny] = dist[x][y] + 1
                q.append((nx,ny))
        mp[ch].clear()
res = dist[tx][ty]
if res == float('inf'):
    res = -1

print(res)


