K = int(input())
num = 7 % K
ctr = 1
while ctr <= K:
    if num % K != 0:
        num = (num * 10 + 7) % K
        ctr += 1        
    else:
        break

if ctr > K:
    print(-1)
else:
    print(ctr)