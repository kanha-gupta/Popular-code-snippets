# Implementation of Bellman Ford algorithm

def bellman_ford(graph,src,V):
    dist = [float("inf")]*V
    dist[src] = 0

    for _ in range(V-1):
        for u,v,w in graph:
            if dist[u]+w<dist[v]:
                dist[v] = dist[u]+w
    
    for u,v,w in graph:
        if dist[u]+w<dist[v]:
            print("Graph contains negative cycle")
            break
    return dist

# Custom Input::
""""
v = 5
g = []
g.append([0, 1, -1])
g.append([0, 2, 4])
g.append([1, 2, 3])
g.append([1, 3, 2])
g.append([1, 4, 2])
g.append([3, 2, 5])
g.append([3, 1, 1])
g.append([4, 3, -3])

print(bellman_ford(g,0,v))

"""
