## 조합

import itertools


## 내풀이
def my_solution(n: int, k: int) -> []:
    result = []
    prev_elements = []
    nums = []

    for i in range(0, n):
        nums.append(i + 1)

    def DFS(elements: []):

        if len(prev_elements) == k:
            print(elements)
            result.append(elements[:])
            return

        for e in elements:
            next_elements = elements[:]
            next_elements.remove(e)
            prev_elements.append(e)
            DFS(next_elements)
            prev_elements.pop()

    for i, n in enumerate(nums):

        next_nums = nums[i:]

        next_nums.remove(n)
        # print(next_nums)
        prev_elements.append(n)
        print(next_nums)
        DFS(next_nums)
        prev_elements.pop()


    return result


if __name__ == '__main__':
    # a = [1, 2, 3, 4]
    # a.remove(1)
    # print(a)
    # a.remove(2)
    # print(a)
    # a.remove(3)
    # print(a)

    print(my_solution(4, 2))
