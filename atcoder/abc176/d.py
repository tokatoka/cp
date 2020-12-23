import sys
from collections import deque
H, W = map(int, sys.stdin.readline().split(' '))
ch, cw = map(int, sys.stdin.readline().split(' '))
dh, dw = map(int, sys.stdin.readline().split(' '))
ch -= 1
cw -= 1
dh -= 1
dw -= 1
board = []
for _ in range(H):
    S = list(sys.stdin.readline().rstrip())
    board.append(S)
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]


def jump(q, board, h, c, cost):
    for dx in range(5):
        for dy in range(5):
            nx = h + dx - 2
            ny = c + dy - 2
            if nx >= 0 and nx < H and ny >= 0 and ny < W and board[nx][ny] == '.':
                board[nx][ny] = cost
                q.append((nx, ny))


cost = 0
q = deque([])
board[ch][cw] = cost
q.append((ch, cw))

while True:
    if board[dh][dw] != '.':
        print(board[dh][dw])
        exit()
    if not len(q):
        break
    anotherq = deque([])
    while q:
        tx, ty = q.pop()
        anotherq.append((tx, ty))
        for dir in range(4):
            if tx + dx[dir] >= 0 and tx + dx[dir] < H and ty + dy[dir] >= 0 and ty + dy[dir] < W and board[tx + dx[dir]][ty + dy[dir]] == '.':
                q.append((tx + dx[dir], ty + dy[dir]))
                board[tx+dx[dir]][ty + dy[dir]] = cost

    # iterate over all cells to find cells which have the cost
    while anotherq:
        h, c = anotherq.pop()
        jump(q, board, h, c, cost + 1)
    cost += 1
# print(board)
if board[dh][dw] != '.':
    print(board[dh][dw])
else:
    print(-1)
