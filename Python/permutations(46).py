## 전화번호문자조합


## 내풀이

def my_solution(nums: []) -> []:
    result_list = []
    result = []
    def DFS(result):

        if len(result) == len(nums):
            result_list.append(result)

            return

        for num1 in nums:
            if num1 in result:
                continue
            result.append(num1)
            DFS(result)
            result.pop()


    for num in nums:

        result.append(num)
        DFS(result)


    return result_list
if __name__ == '__main__':


    print(my_solution([1, 2, 3]))
