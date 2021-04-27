## 키에 따른 대기열 재구성
from typing import *
from operator import itemgetter
import heapq

## 내풀이
def my_solution(people: List[List[int]]) -> List[List[int]]:

    people.sort(key=itemgetter(0), reverse=True)
    # print(people)
    result = []
    for v in people:
        result.insert(v[1], v)

    return result

def solution1(people: List[List[int]]) -> List[List[int]]:
    heap = []
    result = []
    for person in people:
        heapq.heappush(heap, (-person[0], person[1]))
    print(heap)
    while heap:
        person = heapq.heappop(heap)
        result.insert(person[1], [-person[0], person[1]])
    return result
if __name__ == '__main__':
    # people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
    people = [[9,0],[7,0],[1,9],[3,0],[2,7],[5,3],[6,0],[3,4],[6,2],[5,2]]
    print(solution1(people))
    print(my_solution(people))