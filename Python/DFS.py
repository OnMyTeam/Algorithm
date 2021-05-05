## DFS 기본
from typing import *
## 내풀이


def DFS(v, discovered = []) -> []:

    discovered.append(v)
    for i in graph[v]:
        if i not in discovered:
            discovered = DFS(i, discovered)
    return discovered

def my_solution1(graph: {List}) -> List:
    discovered = []

    def DFS(num):
        if num in discovered:
            return

        discovered.append(num)
        for i in graph[num]:
            DFS(i)

    DFS(1)
    return discovered
if __name__ == '__main__':
    graph = {
        1: [2, 3, 4],
        2: [5],
        3: [5],
        4: [],
        5: [6, 7],
        6: [],
        7: [3]
    }

    print(my_solution1(graph))
