# 집합의 표현(1717) 백준
#
import sys
sys.setrecursionlimit(1000000)
#
# n, m = map(int,sys.stdin.readline().split())
#
# set_list = []
# set_dict = {}
# for i in range(0, n+1):
#     set_list.append([i])
# #
# # print(set_dict)
#
# for i in range(0, m):
#     type, a, b = map(int,sys.stdin.readline().split())
#
#
#     if type == 0:
#         first_index = None
#         second_index = None
#         for i, v in enumerate(set_list):
#             if a in v:
#                 first_index = i
#                 break
#         for i, v in enumerate(set_list):
#             if b in v:
#                 second_index = i
#                 break
#         first_set = set_list[first_index]
#         second_set = set_list[second_index]
#
#         if first_set != second_set:
#
#             new_set = list(set(first_set + second_set))
#             set_list.remove(first_set)
#             set_list.remove(second_set)
#             set_list.append(new_set)
#
#
#     else:
#         first_index = None
#         second_index = None
#         for i, v in enumerate(set_list):
#             if a in v:
#                 first_index = i
#                 break
#         for i, v in enumerate(set_list):
#             if b in v:
#                 second_index = i
#                 break
#
#         first_set = set_list[first_index]
#         second_set = set_list[second_index]
#
#         if first_set == second_set:
#             print("YES")
#         else:
#             print("NO")

n, m = map(int,sys.stdin.readline().split())

set_list = []
for i in range(0, n+1):
    set_list.append(i)
#
# print(set_dict)
def find_parent(x):
    if set_list[x] != x:
        set_list[x] = find_parent(set_list[x])

    return set_list[x]
for i in range(0, m):
    type, a, b = map(int,sys.stdin.readline().split())



    if type == 0:

        find_a = find_parent(a)
        find_b = find_parent(b)

        if find_a < find_b:
            set_list[find_b] = find_a
        else:
            set_list[find_a] = find_b


    else:
        find_a = find_parent(a)
        find_b = find_parent(b)
        if find_a == find_b:
            print("YES\n")
        else:
            print("NO\n")






# input = sys.stdin.readline
#
# n, m = map(int, input().split())
# parent = [i for i in range(n + 1)]
# print("parent:", parent)
#
# def find_parent(x):
#     if parent[x] != x:
#         parent[x] = find_parent(parent[x])
#     return parent[x]
#
# def union_parent(a, b):
#     a = find_parent(a)
#     b = find_parent(b)
#     if a < b:
#         parent[b] = a
#     else:
#         parent[a] = b
#     print(parent)
# for _ in range(m):
#     opr, a, b = map(int, input().split())
#     if opr == 0:
#         union_parent(a, b)
#     elif opr == 1:
#         if find_parent(a) == find_parent(b):
#             sys.stdout.write("YES\n")
#         else:
#             sys.stdout.write("NO\n")