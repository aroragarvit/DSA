graph = {
  '5' : ['3','7'],
  '3' : ['2', '4'],
  '7' : ['8'],
  '2' : [],
  '4' : ['8'],
  '8' : []
}

def bfs(graph , node ):
    visited = []
    queue = []

    visited.append(node)
    queue.append(node)

    while queue:
        curr = queue.pop(0)
        print(curr)

        for neighbour in graph[curr]:
            if neighbour not in visited:
                queue.append(neighbour)
                visited.append(neighbour)

bfs( graph, '5') 







