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



if __name__ == '__main__':
    nums = [5,4,-1,7,8]
    print(my_solution(nums))