## 조합

import itertools


## 내풀이
def my_solution(n: int, k: int) -> []:
    result = []
    prev_elements = []

    def DFS(start_num):

        if len(prev_elements) == k:
            result.append(prev_elements[:])
            return

        for e in range(start_num, n):
            element = e + 1
            prev_elements.append(element)
            DFS(e + 1)
            prev_elements.pop()

    DFS(0)

    return result


if __name__ == '__main__':


    print(my_solution(4, 2))
