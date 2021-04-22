## 부분집합

import time
## 내풀이

def my_solution(nums: []) -> []:
    result = []
    subset = []


    def DFS(num_elements):

        if len(subset) == target:
            sort_subset = sorted(subset[::])
            if sort_subset not in result:
                result.append(sort_subset)
            return

        for num in num_elements:

            next_num_elements = num_elements[:]
            next_num_elements.remove(num)
            subset.append(num)
            DFS(next_num_elements)
            subset.pop()
    for i in range(0, len(nums) + 1):
        target = i
        DFS(nums)

    return result
if __name__ == '__main__':

    input = [1,2,3]
    result = my_solution(input)
    print(result)
