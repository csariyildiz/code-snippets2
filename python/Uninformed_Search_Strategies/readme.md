## Uninformed Search Strategies

Uninformed strategies use only the information available in the problem definition.
Uninformed Search includes the following algorithms:

* Breadth First Search (BFS)
* Depth First Search (DFS)
* Uniform Cost Search (UCS)
* Depth Limited Search (DLS)
* Iterative Deepening Search (IDS)
* Bidirectional Search (BS)

## BFS

* Expand shallowest unexpanded node.
* In breadth-first search the frontier is implemented as a FIFO (first-in, first-out) queue. Thus, the path that is selected from the frontier is the one that was added earliest.
* This approach implies that the paths from the start node are generated in order of the number of arcs in the path. One of the paths with the fewest arcs is selected at each stage.

### Pseudocode:

**Input:** A graph G and a starting vertex v of G

**Output:** All vertices reachable from v labeled as explored.

A non-recursive implementation of breadth-first search:

```
Breadth-First-Search(Graph, root):
    
    create empty set S
    create empty queue Q      

    root.parent = NIL
    Q.enqueue(root)                      

    while Q is not empty:
        current = Q.dequeue()
        if current is the goal
            return current
        for each node n that is adjacent to current:
            if n is not in S:
                add n to S
                n.parent = current
                Q.enqueue(n)`
```

## DFS

* Expand deepest unexpanded node.
* The first strategy is depth-first search. In depth-first search, the frontier acts like a lastin first-out (LIFO) stack. The elements are added to the stack one at a time. The one selected and taken off the frontier at any time is the last element that was added.

### Pseudocode:

**Input:** A graph G and a vertex v of G

**Output:** All vertices reachable from v labeled as discovered.

A recursive implementation of DFS:

```
1  procedure DFS(G,v):
2      label v as discovered
3      for all edges from v to w in G.adjacentEdges(v) do
4          if vertex w is not labeled as discovered then
5              recursively call DFS(G,w)
```

A non-recursive implementation of DFS:


```
1  procedure DFS-iterative(G,v):
2      let S be a stack
3      S.push(v)
4      while S is not empty
5          v = S.pop()
6          if v is not labeled as discovered:
7              label v as discovered
8              for all edges from v to w in G.adjacentEdges(v) do
9                  S.push(w)
```
## Exercise

<img class="img-responsive" src="https://acsariyildiz.github.io/images/py8.png">

### Exercise 1:
* Write a program to implement BFS in Fig 1.
* Show which sequences of paths are explored by BFS.
* Use queue/stack data structure that you implemented in Experiment 1.

### Exercise 2:
* Write a program to implement DFS in Fig 1.
* Show which sequences of paths are explored by DFS.
* Use queue/stack data structure that you implemented in Experiment 1.
