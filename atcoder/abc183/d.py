from sys import stdin

N,W = map(int, stdin.readline().split(' '))
arr = [0 for _ in range(2 * pow(10, 5) + 20)]
cur = W
for _ in range(N):
    S,T,P = map(int, stdin.readline().split(' '))
    arr[S] += P
    arr[T] -= P

acc = 0
ok = True
for _ in range(len(arr)):
    acc += arr[_]
    if acc > W:
        ok = False
if ok:
    print("Yes")
else:
    print("No")