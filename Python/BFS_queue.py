## BFS queue


def BFS(v, discovered = []) -> []:
    queue = []
    queue.append(v)

    while queue:
        v = queue.pop(0)

        if v not in discovered:
            discovered.append(v)

            for w in graph[v]:
                queue.append(w)

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

    print(BFS(1))
