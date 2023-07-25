# Dijkstra ALgo
import heapq
# Given a connected graph represented by list of edges, where
# edge[0] = src, edge[1] = dst, edge[2] = weight
# find the shortest path from source to destination
# There are n nodes in the graph
# Time: O(E * log E)
def shortestPath(edges, n, src, dest):
    adj = {}
    for i in range(n):
        s,d,c = edges[i]
        if s in adj:
            adj[s].append((c,d))
        else:
            adj[s] = [(c, d)]
    visited = set()
    current = src
    path = []
    minHeap = [(0, src)]
    while current != dest:
        newCost, newVertex = heapq.heappop(minHeap)
        if newVertex in visited:
            continue
        visited.add(newVertex)
        if newVertex not in adj:
            continue
        path.append(newVertex)
        for edge in adj[newVertex]:
            c,d = edge
            if d not in visited:
                heapq.heappush(minHeap, (newCost + c, d))
        current = newVertex
    return path, newCost

edges = [
    ['1', '2', 10],
    ['1', '3', 3],
    ['2', '4', 2],
    ['3', '2', 4],
    ['3', '4', 8],
    ['3', '5', 2],
    ['4', '5', 5]
]

result = shortestPath(edges, 7, '1', '4')
print(result)