## 문자열 뒤집기
from typing import *

## 내풀이
def my_solution(s: []) -> None:
    s_length = len(s)

    i = 0
    while s_length > 1:
        first_word, second_word = s[i], s[len(s) - 1 - i]
        s[i] = second_word
        s[len(s) - 1 - i] = first_word
        s_length = s_length - 2
        i = i + 1

def my_solution2(s: List[str]) -> None:

    for i in range(int(len(s)/2)):
        first_char = s[i]
        second_char = s[len(s) - i - 1]
        s[i] = second_char
        s[len(s) - i - 1] = first_char




## 투 포인터를 이용한 스왑
def solution1(s: []) -> None:
    left, right = 0, len(s) - 1
    while left < right:
        s[left], s[right] = s[right], s[left]
        left +=1
        right -=1


## 파이썬다운 방식
def solution2(s: []) -> None:
    left, right = 0, len(s) - 1
    while left < right:
        s[left], s[right] = s[right], s[left]
        left += 1
        right -= 1


if __name__ == '__main__':
    print(my_solution2(["H", "a", "n", "n", "a", "h"]))
