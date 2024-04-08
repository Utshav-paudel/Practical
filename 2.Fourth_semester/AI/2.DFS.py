# DFS Algorithm
inputGraph = {
    "A": ["B", "C"],
    "B": ["D", "E"],
    "C": ["F"],
    "D": [],
    "E": ["F"],
    "F": []
}
visitedNodes = []

def depthFirstSearch(graph, node):
    if node not in visitedNodes:
        visitedNodes.append(node)
        neighbours = graph[node]
        for neighbour in neighbours:
            depthFirstSearch(graph, neighbour)
    return visitedNodes

visitedNodes = depthFirstSearch(inputGraph, 'A')
print("DFS result : \n\n")
print(visitedNodes)
print("------------------------------------------------------------")

# BFS Algorithm
inputGraph = {
    "A": ["B", "C"],
    "B": ["D", "E"],
    "C": ["F"],
    "D": [],
    "E": ["F"],
    "F": []
}
visitedNodes = []

def breadthFirstSearch(inputGraph, startNode):
    queue = [startNode]
    while queue:
        node = queue.pop(0)
        if node not in visitedNodes:
            visitedNodes.append(node)
            neighbours = inputGraph[node]
            for neighbour in neighbours:
                queue.append(neighbour)
    return visitedNodes

visitedNodes = breadthFirstSearch(inputGraph, "A")
print("BFS result\n\n")
print(visitedNodes)
print("\nLab by Utshav")
