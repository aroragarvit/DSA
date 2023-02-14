def dfs_iterative (graph , vertex ):
    path = [] # we will use path to store vertex
    stack = [vertex] # we will use stack to store vertex
    while stack : # while stack is not empty
        vertex = stack.pop() # pop the last element from stack
        path.append(vertex) # add it to path
        for neighbour in graph[vertex]: # for each neighbour of vertex
            if neighbour not in path: # if neighbour is not in path
                stack.append(neighbour) # add it to stack
    
    return path
adjacency_matrix = {1: [2, 3], 2: [4, 5],
                    3: [5], 4: [6], 5: [6],
                    6: [7], 7: []}

print(dfs_iterative(adjacency_matrix, 1))
# [1, 2, 4, 6, 7, 5, 3]

