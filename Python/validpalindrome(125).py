## 유효한 팰린드롬
import collections, re
from typing import *
## 내풀이
def my_solution(s: str) -> bool:

    strs = []
    for char in s:
        if char.isalnum():
            strs.append(char.lower())
    reverse_input = ""
    for i in range(len(strs)):
        reverse_input = reverse_input + strs[len(strs)-1 - i]
    print(s)
    print(reverse_input)
    if s == reverse_input:
        return True
    else:
        return False

## 내풀이
def my_solution2(s: str) -> bool:
    strs = []
    for char in s:
        if char.isalnum():
            strs.append(char.lower())
    print(strs)
    for i in range(int(len(strs)/2)):
        if strs[i] != strs[len(strs) -i - 1]:

            return False

    return True
## 풀이1 리스트로 변환
def solution1(input):

    strs = []
    for char in input:
        if char.isalnum():
            strs.append(char.lower())

    # check Palindrome
    while len(strs) > 1:
        if strs.pop(0) != strs.pop():
            return False
    return True

## 풀이2 데크 자료형 사용
def solution2(s: str) -> bool:
    #자료형 데크 선언
    strs: Deque = collections.deque()

    for char in s:
        if char.isalnum():
            strs.append(char.lower())
    print(strs)
    while len(strs) > 1:
        if strs.popleft() != strs.pop():
            return False
    return True

## 풀이2 슬라이싱 사용
def solution3(s: str) -> bool:

    s = s.lower()
    s = re.sub('[^a-z0-9]',  '', s)

    return s == s[::-1]
if __name__ == '__main__':
    print(my_solution2("A man, a plan, a canal: Panama"))
