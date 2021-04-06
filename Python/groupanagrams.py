## 그룹 애너그램

import collections, re

## 내풀이
def my_solution(strs: []) -> [[]]:

    anagrams = {}

    for str in strs:
        sort_str = "".join(sorted(str))
        if sort_str not in anagrams.keys():

            anagrams[sort_str] = []
            anagrams[sort_str].append(str)
        else:
            anagrams[sort_str].append(str)

    return list(anagrams.values())

## 정렬하여 딕셔너리에 추가
def solution1(strs: []) -> [[]]:

    anagrams = collections.defaultdict(list)
    for str in strs:
        sort_str = "".join(sorted(str))

        anagrams[sort_str].append(str)

    return list(anagrams.values())


if __name__ == '__main__':
    print(my_solution(["eat", "tea", "tan", "ate", "nat", "bat"]))
    # [""]
