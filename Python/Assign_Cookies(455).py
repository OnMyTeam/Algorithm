## Assign_Cookies
from typing import *

import collections


## 내풀이
def my_solution(g: List[int], s: List[int]) -> int:
    if not s:
        max_size = 0
    else:
        max_size = max(s)

    greed = []
    for i, c_g in enumerate(g):

        if c_g <= max_size:
            greed.append(c_g)

    s.sort()
    greed.sort()
    result = 0
    while greed:

        greed_size = greed.pop()

        for cookie_size in s:
            if cookie_size >= greed_size:
                result += 1
                s.remove(cookie_size)
                break


    return result


#  그리디 알고리즘
def solution1(g: List[int], s: List[int]) -> int:
    g.sort()
    s.sort()
    print(g)
    print(s)
    child_i = cookie_j = 0

    while child_i < len(g) and cookie_j < len(s):
        if s[cookie_j] >= g[child_i]:
            child_i +=1
        cookie_j +=1


    return child_i
if __name__ == '__main__':
    g = [1, 2, 3]
    s = [3]

    print(solution1(g, s))
