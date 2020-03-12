#Write a program to implement BFS in Fig 1.  
#Show which sequences of paths are explored by BFS.  
#Use queue/stack data structure that you implemented in Experiment 1. 

from collections import deque

#Define bfs function.
def bfs(g, start):
    #Define level and parent nodes.
    queue, enqueued = deque([(None, start)]), set([start])
    #Loop in layers.
    while queue:
        
        parent, n = queue.popleft()
        yield parent, n
        #Yield is a keyword that is used like return, except the function will return a generator.
        new = set(g[n]) - enqueued
        enqueued = enqueued | new
        queue.extend([(n, child) for child in new])

def dfs(g, start):
    stack, enqueued = [(None, start)], set([start])
    while stack:
        parent, n = stack.pop()
        yield parent, n
        new = set(g[n]) - enqueued
        enqueued = enqueued | new
        stack.extend([(n, child) for child in new])

def shortest_path(g, start, end):
    parents = {}
    for parent, child in dfs(g, start):
        parents[child] = parent
        if child == end:
            revpath = [end]
            while True:
                parent = parents[child]
                revpath.append(parent)
                if parent == start:
                    break
                child = parent
            return list(reversed(revpath))
    return None

if __name__ == '__main__':

    graph = {'A': ['B', 'E'],
             'B': ['C', 'D'],
             'C': ['B', 'D'],
             'D': ['B', 'C'],
             'E': ['F'],
             'F': []}

    print(shortest_path(graph, 'A', 'F'))
