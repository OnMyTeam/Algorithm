## 섬의개수


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
if __name__ == '__main__':
    grid = [
        ["1", "1", "0", "0", "0"],
        ["1", "1", "0", "0", "0"],
        ["0", "0", "1", "0", "0"],
        ["0", "0", "0", "1", "1"]
    ]
    print(my_solution(grid))
