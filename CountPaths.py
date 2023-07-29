# Count Paths - Matrix DFS Approach
# Count the unique paths from top left to bottom right
# A single path may only move along 0's and can't visit the same cell more than once

matrix = [
    [0,0,0,0],
    [1,1,0,0],
    [0,0,0,1],
    [0,1,0,0]
]

def countPathsMatrixDFS(r, c, visit):
    rows, cols = len(matrix), len(matrix[0])
    # if they go out of bounds
    if r < 0 or c < 0 or r == rows or c == cols:
        return 0  # return 0, dont do anything and come out
    # if it blocked
    if matrix[r][c] == 1:
        return 0
    # if it is already visited
    if (r, c) in visit:
        return 0
    # if we reached the destination, that means the finish line (bottom-right)
    if r == rows - 1 and c == cols - 1:
        return 1 # we found a path from start to the end
    
    # mark as visited
    visit.add((r, c))
    
    paths = 0
    # move right
    paths += countPathsMatrixDFS(r, c + 1, visit)
    # move left
    paths += countPathsMatrixDFS(r, c - 1, visit)
    # move top
    paths += countPathsMatrixDFS(r - 1, c, visit)
    # move down
    paths += countPathsMatrixDFS(r + 1, c, visit)

    visit.remove((r, c)) # mark as unvisited

    # return the number of paths
    return paths


paths = countPathsMatrixDFS(0, 0, set())
print(paths)