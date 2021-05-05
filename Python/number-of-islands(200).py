## 섬의개수
from typing import *

## 내풀이
def my_solution(grid = [[]]) -> int:
    island_count = 0;
    directions  = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    def DFS(grid, i, j):
        if i < 0 or i >= len(grid) or \
                j < 0 or j >= len(grid[0]) or \
                grid[i][j] != '1':
            return
        grid[i][j] = '#'
        for x, y in directions :
            DFS(grid, i + x, j + y)


    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == '1':
                DFS(grid, i, j)

                island_count += 1



    return island_count

def my_solution2(grid: List[List[str]]) -> int:
    rotate = [(0,1), (-1,0), (0, -1), (1,0)]
    def DFS(x:int, y:int):
        if x < 0 or x >= len(grid) or \
            y < 0 or y >= len(grid[0]) or \
                grid[x][y] == "0":

            return
        grid[x][y] = "0"

        for r in rotate:
            sub_x = r[0]
            sub_y = r[1]
            DFS(x+sub_x, y+sub_y)
    island_count = 0
    for x in range(len(grid)):
        for y in range(len(grid[x])):

            if grid[x][y] == "1":
                DFS(x, y)
                island_count += 1

    return island_count
if __name__ == '__main__':
    grid = [  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]]

    print(my_solution2(grid))
