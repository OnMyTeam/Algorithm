## 최대 서브 배열
from typing import *

import collections

## 내풀이
def my_solution(nums: List[int]) -> int:
    memorize = []


    for num in nums:
        memorize.append(num)
    max_num = max(nums)

    for i in range(1, len(nums)):

        for k in range(i, len(nums)):

            sum = nums[k] + memorize[k - i]
            memorize[k-i] = sum
            max_num = max(max_num, sum)

    return max_num


def solution1(nums: List[int]) -> int:
    for i in range(1, len(nums)):
        if nums[i-1] > 0:
            nums[i] += nums[i-1]

    return max(nums)
if __name__ == '__main__':
    nums = [-2,1,-3,4,-1,2,1,-5,4]
    print(my_solution(nums))
    print(solution1(nums))