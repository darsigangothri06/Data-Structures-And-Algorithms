# shortest path from source to destination using adjacency list - BFS
from collections import deque
edges = [["A", "B"], ["B", "C"], ["B", "E"], ["C", "E"], ["E", "D"]]

adjList = {}

for src, dst in edges:
    if src not in adjList:
        adjList[src] = []
    if dst not in adjList:
        adjList[dst] = []
    adjList[src].append(dst)

def bfs(node, target, adjList, visit):
    length = 0
    visit = set()
    visit.add(node)
    que = deque()
    que.append(node)

    while que:
        for _ in range(len(que)):
            curr = que.popleft()
            if curr == target:
                return length

            for neighbor in adjList[curr]:
                if neighbor not in visit:
                    visit.add(neighbor)
                    que.append(neighbor)
        length += 1    
    return length

print(bfs("A", "E", adjList, set()))