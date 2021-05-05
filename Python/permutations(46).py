## 순열
from typing import *


## 내풀이

def my_solution(nums: []) -> []:
    result_list = []

    def DFS(result, index):

        if len(result) == len(nums):
            result_list.append(result)

            return

        for num1 in nums:
            if num1 in result:
                continue
            result.append(num1)
            DFS(result, index + 1)
            result = result[:index]

    index = 0
    for num in nums:
        result = []
        result.append(num)
        DFS(result, index + 1)

    return result_list

def my_solution2(nums: List[int]) -> List[List[int]]:
    result_list = []
    result = []


    def DFS(sub_nums):
        if len(result) == len(nums):
            result_list.append(result[:])
            return

        for num in sub_nums:
            result.append(num)
            next_nums = sub_nums[:]
            next_nums.remove(num)
            DFS(next_nums)
            result.pop()

    DFS(nums)
    return result_list
if __name__ == '__main__':
    nums = [1, 2, 3, 4]
    print(my_solution2(nums))
