## 조합
from typing import *



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

def my_solution2(n: int, k: int) -> List[List[int]]:
    result_list = []
    result = []


    def DFS(index):
        if len(result) == k:
            result_list.append(result[:])
            return

        for i in range(index, n):
            result.append(i+1)
            DFS(i + 1)
            result.pop()

    DFS(0)
    return result_list
if __name__ == '__main__':
    n = 1
    k = 1

    print(my_solution2(n, k))
