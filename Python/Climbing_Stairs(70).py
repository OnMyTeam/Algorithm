## 계단 오르기
from typing import *

import collections

## 내풀이
def my_solution(n: int) -> int:

    if n == 0:
        return n
    memorize = []
    memorize.append(1)
    memorize.append(2)

    for i in range(0, n):

        if n == 0:
            return memorize[n-1]
        if n == 1:
            return memorize[n-1]
        if i >= (2):
            memorize.append(memorize[i - 1] + memorize[i - 2])


    return memorize[n-1]



if __name__ == '__main__':
    n = 5
    print(my_solution(n))