## 문자 해독(1593) 백준

import sys, collections

W_length, S_length = map(int,sys.stdin.readline().split())
W = input()
S = input()


w_count = collections.Counter(W)
count = 0
g_count = collections.Counter(S[0:W_length])
same = True
for k, v in g_count.items():
    if k not in w_count:
        same = False
        break
    else:
        if v != w_count[k]:
            same = False
            break

if same:
    count += 1

for i in range(W_length, S_length):
    if g_count[S[i - W_length]] >=2:
        g_count[S[i - W_length]] -=1
    else:
        del(g_count[S[i-W_length]])

    if S[i] not in g_count:
        g_count[S[i]] = 1
    else:
        g_count[S[i]] += 1

    same = True
    for k, v in g_count.items():
        if k not in w_count:
            same = False
            break
        else:
            if v != w_count[k]:
                same = False
                break

    if same:
        count += 1

print(count)

