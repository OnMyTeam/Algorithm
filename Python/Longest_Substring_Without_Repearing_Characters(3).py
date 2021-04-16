## 중복문자없는 가장 긴 부분 문자열


import re, operator, collections

## 내풀이
def my_solution(s: str) -> int:
    if s == "":
        return 0
    if s == " " or len(s) == 1:
        return 1
    substrings = []
    characters_length_dict = {}
    prev_char = ''

    def DFS(str, count):

        if str == "":
            chars = "".join(substrings)
            characters_length_dict[chars] = count
            return
        next_char = str[0]
        if next_char in substrings:

            chars = "".join(substrings)
            characters_length_dict[chars] = count
            return
        substrings.append(next_char)
        next_strings = str[1::]

        DFS(next_strings, count + 1)

    for i, char in enumerate(s):
        count = 0
        start_index = i + 1
        if prev_char == i:
            continue
        prev_char = char
        next_strings = s[start_index::]
        # print(next_strings)
        substrings.append(char)

        DFS(next_strings, count + 1)
        substrings = []
    return max(characters_length_dict.values())

def my_solution1(s: str) -> int:

    pass
if __name__ == '__main__':
    s = "pwwkew"

    print(my_solution(s))

