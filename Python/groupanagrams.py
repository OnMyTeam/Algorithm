## 그룹 애너그램

import collections, re
from typing import *
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

## 내풀이
def my_solution2(strs: []) -> [[]]:
    grouping = collections.defaultdict(list)
    result = []
    for s in strs:

        grouping["".join(sorted(s))].append(s)

    for v in grouping.items():
        result.append(v[1])

    return result
## 정렬하여 딕셔너리에 추가
def solution1(strs: []) -> [[]]:

    anagrams = collections.defaultdict(list)
    for str in strs:
        sort_str = "".join(sorted(str))

        anagrams[sort_str].append(str)

    return list(anagrams.values())


if __name__ == '__main__':
    print(my_solution2(["eat", "tea", "tan", "ate", "nat", "bat"]))
    # [""]
