## 중복문자없는 가장 긴 부분 문자열


import re, operator, collections

## 내풀이
def my_solution(s: str) -> int:
    max_length = 0
    length = 0
    string = ""
    used_char = {}
    if len(''.join(set(s))) == 1:
        return 1
    count = 0

    for index, char in enumerate(s):

        if char not in string:
            used_char[char] = index
            string += char
            length += 1
            if count == (len(s) - 1):

                max_length = max(length, max_length)
        else:
            print(string)
            char_index = used_char[char]
            string = string[(char_index + 1)::] + char

            max_length = max(max_length, index - char_index + 1)


        count += 1

    return max_length

def solution1(s: str) -> int:
    max_length = start_index = 0
    used_char = {}
    for index, char in enumerate(s):

        if char in used_char and start_index <= used_char[char]:

            start_index = used_char[char] + 1
        else:
            max_length = max(max_length, index - start_index + 1)

        used_char[char] = index
    return max_length
if __name__ == '__main__':
    s = "abcabcbb"
    s = "aabaab!bb"
    # s = "dvdf"
    print(my_solution(s))

