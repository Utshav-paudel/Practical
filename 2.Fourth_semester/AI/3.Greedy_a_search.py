# Greedy Best-First
inputGraph = {
    'A': [('B', 4), ('D', 12)],
    'B': [('A', 9), ('C', 4)],
    'C': [('D', 4), ('B', 7)],
    'D': [('A', 9), ('C', 5)]
}
goal = "C"

def gbfs(graph, start):
    queue = [start]
    visitedNode = []
    while queue:
        queue = sorted(queue, key=lambda x: x[1])
        node = queue.pop(0)
        if node not in visitedNode:
            visitedNode.append(node)
            if node[0] == goal:
                break
            neighbours = graph[node[0]]
            for neighbour in neighbours:
                queue.append(neighbour)
    return visitedNode
print("Greedy Best first search : ")
print(gbfs(inputGraph, ("A", 13)))
print("\n\n")

# A*
inputGraph = {
    'A': [('B', 7, 6), ('D', 8, 5)],
    'B': [('A', 7, 9), ('C', 9, 3)],
    'C': [('D', 5, 5), ('B', 9, 4)],
    'D': [('A', 5, 11), ('C', 5, 3)],
}
goal = "D"

def gbfs(graph, start):
    rootToParentCost = 0
    queue = [start + (rootToParentCost,)]
    visitedNodes = []
    while queue:
        queue = sorted(queue, key=lambda x: x[1] + x[2] + x[3])
        node = queue.pop(0)
        rootToParentCost = node[1] + node[3]
        if node not in visitedNodes:
            visitedNodes.append(node)
            if node[0] == goal:
                break
            neighbours = graph[node[0]]
            for neighbour in neighbours:
                queue.append(neighbour + (rootToParentCost,))
    return visitedNodes

visitedNodes = gbfs(inputGraph, ('A', 5, 10))
print("A* search result : ")
print(visitedNodes)
print("Lab By Utshav Paudel")
