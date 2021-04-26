## 주식을 사고팔기 가장좋은 시점2
from typing import *

## 내풀이
def my_solution(prices: List[int]) -> int:
    sum_nums = 0
    result = []
    type = "BUY"

    def DFS(num, prices, type, sum_nums):

        if num == len(prices):
            result.append(sum_nums)

        for i, p in enumerate(prices):

            if type == "SELL" and ((sum_nums + p)) >= 0:

                next_prices = prices[i:]
                next_prices.remove(p)
                print(type, num, sum_nums)
                type = "BUY"
                sum_nums += p

                DFS(num + 1, next_prices, type, sum_nums)
                sum_nums -= p
            if type == "BUY":


                next_prices = prices[i:]
                next_prices.remove(p)
                print(type, num, sum_nums, next_prices, p)
                type = "SELL"
                sum_nums -= p

                DFS(num + 1, next_prices, type, sum_nums)
                sum_nums += p


    DFS(0, prices, type, sum_nums)
    return result


if __name__ == '__main__':
    prices = [7, 1, 5, 3, 6, 4]
    print(my_solution(prices))