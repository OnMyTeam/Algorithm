## 태스크 스케쥴러
from typing import *

import collections

## 내풀이
def my_solution(s: str) -> str:
    result = None
    max_value = 0
    if len(s) == 1:
        return s
    for i1, c1 in enumerate(s):

        for i2 in range(len(s)-1, -1, -1):

            if s[i2] == c1:

                str = s[i1:i2+1]

                if str == str[::-1]:

                    new_max_value = max(max_value, len(str))
                    if new_max_value > max_value:
                        result = str
                        max_value = new_max_value
    return result
def my_solution2(s: str) -> str:
    result = None
    max_value = 0
    if len(s) == 1:
        return s
    for i1, c1 in enumerate(s):
        if max_value >= (len(s) - i1 + 1):
            break
        for i2 in range(len(s)-1, -1, -1):

            if s[i2] == c1:

                str = s[i1:i2+1]

                if str == str[::-1]:

                    new_max_value = max(max_value, len(str))
                    if new_max_value > max_value:
                        result = str
                        max_value = new_max_value


    return result



def my_solution3(s: str) -> str:
    result = None
    max_value = 0
    if len(s) == 1:
        return s
    for i1 in range(len(s)-1, -1, -1):

        for i2, c2 in enumerate(s):

            if s[i2] == c2:

                str = s[i2:i1+1]

                if str == str[::-1]:

                    new_max_value = max(max_value, len(str))
                    if new_max_value > max_value:
                        result = str
                        max_value = new_max_value

        if max_value >= i1 + 1:
            break
    return result

# 중앙을 중심으로 확장하는 풀이
def solution1(s: str) -> str:

    def expand(left:int, right:int) -> str:
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return s[left + 1:right]

    if len(s) < 2 or s == s[::-1]:
        return s
    result = ''

    for i in range(len(s) - 1):
        result = max(result,
                     expand(i, i+1),
                     expand(i, i+2),
                     key=len)
    return result


if __name__ == '__main__':

    s = "babad"
    s = "cbbd"
    s = "babad"
    print(solution1(s))