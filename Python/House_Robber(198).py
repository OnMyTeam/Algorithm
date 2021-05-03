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
    memorize.append(nums[0] + nums[2])
    max_num = max(memorize)
    for i in range(len(nums)):

        if i < 3:
            max_num = max(max_num, nums[i])
        else:
            sum = nums[i] + memorize[i - 2]
            sum1 = nums[i] + memorize[i - 3]

            sub_max_num = max(sum, sum1)
            memorize.append(sub_max_num)

            max_num = max(max_num, sub_max_num)

    return max_num



if __name__ == '__main__':
    n = [1, 2, 3, 1]
    print(my_solution(n))