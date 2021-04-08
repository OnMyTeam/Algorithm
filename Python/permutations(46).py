## 전화번호문자조합


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
if __name__ == '__main__':


    print(my_solution([1, 2, 3, 4]))
