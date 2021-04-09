## 전화번호문자조합

import itertools

## 내풀이
def my_solution(nums: []) -> []:
    result_list = []

    def DFS(result):

        if len(result) == len(nums):
            result_list.append(result[:])

            return

        for num1 in nums:
            if num1 in result:
                continue
            result.append(num1)
            DFS(result)
            result.pop()

    for num in nums:
        result = []
        result.append(num)
        DFS(result)

    return result_list

def solution1(nums: []) -> []:
    results = []
    prev_elements = []

    def DFS(elements):

        if len(elements) == 0:
            results.append(prev_elements[:])
            return
        for e in elements:
            next_elements = elements[:]
            next_elements.remove(e)
            prev_elements.append(e)
            DFS(next_elements)
            prev_elements.pop()
    DFS(nums)
    return results

# itertools 모듈 사용
def solution2(nums: []) -> []:

    return list(itertools.permutations(nums))
if __name__ == '__main__':


    print(solution2([1, 2, 3]))
