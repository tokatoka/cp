from sys import stdin

r1,c1 = map(int, stdin.readline().split(' '))
r2,c2 = map(int, stdin.readline().split(' '))

if (r2 - r1) == 0 and (c2 - c1) == 0:
    print(0)
elif abs(r2 - r1) + abs(c2 - c1) <= 3 or r2 + c2 == r1 + c1 or r2 - c2 == r1 - c1:
    print(1)
elif abs(r2 - r2) + abs(c2 - c1) <= 6:
    print(2)
elif abs(r1 + c1 - r2 - c2) <= 3 or abs((r1 - c1 - r2 + c2)) <= 3:
    print(2)
elif (c2 - r2) % 2 == (c1 - r1) % 2:
    print(2)
else:
    print(3)