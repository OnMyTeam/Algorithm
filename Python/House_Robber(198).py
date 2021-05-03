## 집 도둑
from typing import *

import collections

## 내풀이
def my_solution(nums: List[int]) -> int:
    max_num = 0
    if not nums:
        return max_num
    if len(nums) <= 2:
        return max(nums)
    memorize = []
    memorize.append(nums[0])
    memorize.append(nums[1])

    for i in range(len(nums)):
        if i < 2:
            max_num = max(max_num, nums[i])
        else:
            sum = nums[i] + memorize[i - 2]

            memorize.append(sum)
            max_num = max(max_num, sum)


    return max_num



if __name__ == '__main__':
    n = [1, 3, 1]
    print(my_solution(n))