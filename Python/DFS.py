## 유효한 팰린드롬
import collections, re
## 내풀이


def DFS(v, discovered = []) -> []:

    discovered.append(v)
    for i in graph[v]:
        if i not in discovered:
            discovered = DFS(i, discovered)
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

    print(DFS(1))
