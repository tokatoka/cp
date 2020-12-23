from sys import stdin
S = stdin.readline().rstrip()

if len(S) == 1:
    print(["No","Yes"][S in ['0', '8']])
elif len(S) == 2:
    print(["No","Yes"][S in ['16','24','32','40','48','56','64','72','80','88','96'] or S[::-1] in ['16','24','32','40','48','56','64','72','80','88','96']])
else:
    eight_list = []
    eight = 0
    while eight < 1000:
        eight_list.append(f"{eight:03}")
        eight += 8
    mp_list = []
    for _ in eight_list:
        mp = [0 for _ in range(10)]
        for i in range(3):
            mp[int(_[i])] += 1
        mp_list.append(mp)
    s_list = [0 for _ in range(10)]
    for _ in range(len(S)):
        s_list[int(S[_])] += 1
    for _ in mp_list:
        ok = True
        for i in range(10):
            if _[i] > s_list[i]:
                ok = False
        if ok:
            print("Yes")
            exit()
    print("No")