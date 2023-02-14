def dfs_recursive (graph , vertex , path =[]):
    path.append(vertex)  # each vertex on which we are calling the function  we must add to path so after while calling function on some we could check if vertex in path
    # we must not think about calling function on that vertex 

    for neighbour in graph[vertex]:
        if neighbour not in path:    # if in path then dont just call 
            dfs_recursive(graph , neighbour , path ) # if a vertex has no neighbour then it will return and go to next line and print path itself as function ends at this line

       
        
    return path

adjacency_matrix = {1: [2, 3], 2: [4, 5],
                    3: [5], 4: [6], 5: [6],
                    6: [7], 7: []}

print(dfs_recursive(adjacency_matrix, 2))
# [1, 2, 4, 6, 7, 5, 3]

