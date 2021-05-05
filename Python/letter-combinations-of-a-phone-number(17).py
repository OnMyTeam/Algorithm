## 전화번호문자조합
from typing import *

## 내풀이

def my_solution(digits: str) -> []:

    phone_letters = {
        "2": ["a", "b", "c"],
        "3": ["d", "e", "f"],
        "4": ["g", "h", "i"],
        "5": ["j", "k", "l"],
        "6": ["m", "n", "o"],
        "7": ["p", "q", "r", "s"],
        "8": ["t", "u", "v"],
        "9": ["w", "x", "y", "z"],
    }

    Output = []
    if digits == "":
        return Output
    def DFS(letter, index):
        if index == len(digits):
            Output.append(letter)
            return
        digit = digits[index]

        for phone_letter in phone_letters[digit]:

            DFS(letter + phone_letter, index + 1)


    DFS('', 0)


    return Output

def my_solution2(digits: str) -> List[str]:
    result = []
    phone_letters = {
        "2": "abc",
        "3": "def",
        "4": "ghi",
        "5": "jkl",
        "6": "mno",
        "7": "pqrs",
        "8": "tuv",
        "9": "wxyz",
    }
    if digits.strip() == "":
        return result
    def DFS(str, index):
        if index == len(digits):

            result.append(str)
            return



        for letter in phone_letters[digits[index]]:

            DFS(str + letter, index + 1)


    DFS('', 0)


    return result
if __name__ == '__main__':
    digits = " "
    # print(len(digits))
    print(my_solution2(digits))
