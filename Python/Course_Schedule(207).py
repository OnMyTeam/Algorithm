## 코스스케쥴

import collections
## 내풀이

def my_solution(numCourses: int, prerequisites: [[int]]) -> bool:
     graph = collections.defaultdict(list)
     traced = set()
     for x, y in prerequisites:
         graph[x].append(y)

     def dfs(i):
         if i in traced:
             return False

         traced.add(i)
         for y in graph[i]:
             if not dfs(y):
                 return False
         traced.remove(i)

         return True

     for x in graph:
         if not dfs(x):
             return False

     return True
if __name__ == '__main__':

    numCourses = 2
    prerequisites = [[1, 0]]
    result = my_solution(numCourses, prerequisites)
    print(result)