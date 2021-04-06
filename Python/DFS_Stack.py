## 유효한 팰린드롬
import collections, re
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

    print(DFSiterative(1))
