## 보석과 돌


import re, operator, collections

## 내풀이
def my_solution(jewels: str, stones: str) -> int:
    jewels_count = 0
    for c in jewels:
        jewels_count += stones.count(c)

    return jewels_count

if __name__ == '__main__':
    jewels = "aA"
    stones = "aAAbbbb"
    print(my_solution(jewels, stones))

