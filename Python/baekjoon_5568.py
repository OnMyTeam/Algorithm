# 카드놓기(5568) 백준
from itertools import zip_longest
import sys

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())

num_set = []
result = []
result_list = []
for _ in range(n):
    k = int(sys.stdin.readline())
    num_set.append(k)



def DFS(sub_num_set):
    if len(result) == m:
        if "".join(result[:]) not in result_list:
            result_list.append("".join(result[:]))
        return

    for i1, v1 in enumerate(sub_num_set):
        result.append(str(v1))

        prev_num_set1 = sub_num_set[:]
        del prev_num_set1[i1]
        DFS(prev_num_set1)
        result.pop()


for i, v in enumerate(num_set):
    result.append(str(v))
    prev_num_set = num_set[:]
    del prev_num_set[i]
    DFS(prev_num_set)
    result.pop()

print(len(result_list))
