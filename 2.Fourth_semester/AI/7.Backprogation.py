N = 9

def checkSafe(grid, row, col, num):
    for x in range(N):
        if grid[row][x] == num:
            return False
    for x in range(N):
        if grid[x][col] == num:
            return False
    startRow = row - row % 3
    startCol = col - col % 3
    for i in range(3):
        for j in range(3):
            if grid[i + startRow][j + startCol] == num:
                return False
    return True

def solveSudoku(grid, row, col):
    if (row == N - 1 and col == N):
        return True
    if col == N:
        row += 1
        col = 0
    if grid[row][col] > 0:
        return solveSudoku(grid, row, col + 1)
    for num in range(1, N + 1, 1):
        if checkSafe(grid, row, col, num):
            grid[row][col] = num
            if solveSudoku(grid, row, col + 1):
                return True
            grid[row][col] = 0
    return False

sudokuProblem = [
    [0, 9, 0, 5, 6, 1, 0, 0, 7],
    [0, 3, 0, 0, 0, 8, 0, 0, 1],
    [0, 0, 8, 0, 4, 0, 0, 5, 9],
    [7, 0, 0, 2, 8, 0, 1, 0, 0],
    [9, 0, 6, 0, 0, 0, 8, 7, 0],
    [0, 0, 0, 0, 0, 6, 5, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 3, 0, 0, 2, 0, 0, 0],
    [0, 4, 9, 7, 1, 0, 0, 0, 5]
]

print("The solution of above sudoku is:\n")
if solveSudoku(sudokuProblem, 0, 0):
    for i in range(N):
        for j in range(N):
            print(sudokuProblem[i][j], end=" ")
        print()
else:
    print("Solution failed")
print("\n\tLAB by Utshav Paudel")