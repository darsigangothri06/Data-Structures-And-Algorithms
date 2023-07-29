# Find the shortest length from top-left to bottom-right
# Matrix BFS
import collections

matrix = [
    [0,0,0,0],
    [1,1,0,0],
    [0,0,0,1],
    [0,1,0,0]
]

def matrixBFS():
    shortestLength = 0

    queue = collections.deque()
    rows, cols = len(matrix), len(matrix[0])
    visit = set()
    queue.append((0, 0))
    while queue:
        qLen = len(queue)
        for _ in range(qLen):
            r, c = queue.popleft()
            if r == rows - 1 and c == cols - 1:
                return shortestLength
            neighbors = [[1, 0], [0, 1], [-1, 0], [0, -1]]

            for (nr, nc) in neighbors:
                row, col = r + nr, c + nc
                if row < 0 or col < 0 or row == rows or col == cols or matrix[row][col] == 1 or (row, col) in visit:
                    continue
                queue.append((row, col))
                visit.add((row, col))
        shortestLength += 1
    return shortestLength

sL = matrixBFS()
print(sL)