## 조합의 합


import bisect

## 내풀이
def my_solution(candidates: [int], target: int) -> [[int]]:
    result = []
    combinations = []


    def DFS():

        if sum(combinations) > target:
            return
        sorted_combinations = sorted(combinations)
        if sum(combinations) == target and sorted_combinations not in result:
            result.append(combinations[::])
            return

        for cd in candidates:
            combinations.append(cd)
            DFS()
            combinations.pop()

    DFS()
    return result

if __name__ == '__main__':
    candidates = [5,10,8,4,3,12,9]
    result = [[2,3,2]]
    a = [2,2,3]
    if a not in result:
        print(a)
    target = 27
    l = []
    # for r in [4, 9, 13, 16, 18, 27, 4, 49, 5, 56, 5, 1, 63, 64, 73, 78, 84, 98, 98]:
    #     position = bisect.bisect(l, r)
    #     bisect.insort(l, r)
    #     print('%2d %2d' % (r, position), l)
    # print(my_solution(candidates, target))


