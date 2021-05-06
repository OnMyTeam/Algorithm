# 가장 가까운 공통 조상(3584) 백준
from itertools import zip_longest
import sys
# input = sys.stdin.readline()


def run(start_node, grid, node1, node2):

    result = []
    result_list = []

    def DFS(key):

        if (node1 in result) or (node2 in result):

            result_list.append(result[:])

            return
        if key not in grid:
            return
        for v in grid[key]:
            result.append(v)
            DFS(v)
            result.pop()

    result.append(start_node)
    DFS(start_node)


    if len(result_list) == 1:
        print(result_list[0][-1])


    if len(result_list) == 2:
        count = 0
        for i1, i2 in zip_longest(result_list[0],result_list[1]):
            if node1 in result_list[0] or node2 in result_list[0]:

                if i1 != i2:
                    print(result_list[0][count - 1])
                    return
            count +=1

t = int(sys.stdin.readline())
grid = {}
new_grid = {}
for i in range(t):
    n = int(sys.stdin.readline())
    for k in range(n):
        edge = sys.stdin.readline().split()
        if k < n - 1:

            p, c = (edge[0], edge[1])
            if p not in grid:
                grid[p] = []
                grid[p].append(c)
            else:
                grid[p].append(c)
        else:
            node1, node2  = (edge[0],edge[1])


    grid_idex = {}
    ordered_grid_keys = list(grid.keys())

    root_node = None
    for key,value in grid.items():
        root_node = key
        for k, v in grid.items():
            if key in v:
                root_node = k
                break

        if root_node == key:
            break

    run(root_node, grid,node1, node2)


    grid = {}


# import sys
#
# T = int(sys.stdin.readline())
#
# for _ in range(T):
#     N=int(sys.stdin.readline())
#     p_list=[0 for _ in range(N+1)]      #각 노드의 부모노드 저장
#     # print("p_list ", p_list)
#     for _ in range(N-1):
#         p,c=map(int,sys.stdin.readline().split())
#         # print(p, c)
#         p_list[c]=p                     #부모 노드 저장
#
#     a,b=map(int,sys.stdin.readline().split())
#
#     a_parent=[a]
#     b_parent=[b]
#     #각노드의 부모노드가 루트일때까지 모두 저장
#     # print("p_list ",p_list)
#     # print("a_parent ", a_parent)
#     # print("b_parent ", b_parent)
#     while p_list[a]:
#         a_parent.append(p_list[a])
#         a=p_list[a]
#
#     while p_list[b]:
#         b_parent.append(p_list[b])
#         b=p_list[b]
#
#                                         #같은 레벨로 맞추고 부모노드 같은거 찾기
#
#     a_level=len(a_parent)-1
#     b_level=len(b_parent)-1
#                                         # 루트노드부터 차례대로 비교
#     while a_parent[a_level]==b_parent[b_level]:   #부모노드가 같지 않을때까지
#         a_level-=1
#         b_level-=1
#
#     print(a_parent[a_level+1])