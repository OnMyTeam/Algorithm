## 상위 K 빈도요소


import operator

## 내풀이
def my_solution(nums: [int], k: int) -> [int]:

    num_count = {}
    Output = []
    for num in nums:
        if num not in num_count:
            num_count[num] = 1
        else:
            num_count[num] += 1
    count = 0
    for key, value in sorted(num_count.items(), key = operator.itemgetter(1), reverse=True):

        Output.append(key)
        count += 1

        if count == k:
            break

    return Output

if __name__ == '__main__':
    nums = [4, 1, -1, 2, -1, 2, 3]
    k = 2

    print(my_solution(nums, k))

