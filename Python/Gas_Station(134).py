## Gas Station
from typing import *

import collections

## 내풀이
def my_solution(gas: List[int], cost: List[int]) -> int:
    enough_gas = []
    index = 0
    for g, c in zip(gas, cost):
        if (g - c) >= 0:
            enough_gas.append([g-c, g,c, index])
        index += 1
    enough_gas.sort(key=lambda x: (-x[0], x[1], x[2]))
    success = 0

    for _, eg, ec, i in enough_gas:
        remain_gas = 0
        index = i

        for i in range(index, index + len(gas)):
            if i >= len(gas):
                i = i - len(gas)
            remain_gas += (gas[i] - cost[i])
            if remain_gas < 0:
                break
        if remain_gas >=0:

            success = 1
            return index

    if success == 0:
        return -1
if __name__ == '__main__':
    gas = [1,2,3,4,5]
    cost = [3,4,5,1,2]


    print(my_solution(gas, cost))