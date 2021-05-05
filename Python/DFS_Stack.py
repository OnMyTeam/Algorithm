## DFS 기본 스택
from typing import *
## 내풀이


def DFSiterative(v) -> []:
    discovered = []
    stack = [v]
    print(stack)
    stack.append(v)

    while len(stack) > 0:
        v = stack.pop()
        if v not in discovered:
            discovered.append(v)
            for i in graph[v]:
                stack.append(i)



    return discovered


def my_solution1(graph: List[List]) -> List:
    result = []
    route = []
    route.append(1)

    while route:

        r = route.pop()
        if r not in result:
            result.append(r)
            for i in graph[r]:
                route.append(i)
    return result
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
