from sys import stdin

N = int(stdin.readline())
positive = []
negative = []
pt = 0
mt = 0
for _ in range(N):
    s = stdin.readline().rstrip()
    total, minimum = 0, 0
    for c in s:
        if c == '(':
            total += 1
        else:
            total -= 1
            minimum = min(minimum, total)
    
    if total >= 0:
        if minimum == 0:
            pt += total
        else:
            positive.append((minimum, total))
    else:
        total, minimum = -total, minimum-total
        if minimum == 0:
            mt += total
        else:
            negative.append((minimum, total))
def check(pt, brackets):
    brackets.sort(reverse = True)
    for m, t in brackets:
        if pt + m < 0:
            return -1
        pt += t
    return pt
pt = check(pt, positive)
mt = check(mt, negative)

if(pt == -1) or (mt == -1) or (pt != mt):
    print('No')
else:
    print("Yes")
