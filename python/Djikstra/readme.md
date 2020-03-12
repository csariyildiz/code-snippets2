## Graph Data Structure

* A graph is simply a collection of nodes plus edges
  * Linked lists, trees, and heaps are all special cases of graphs
* The nodes are known as vertices (node = “vertex”)

**Formal Definition:** A graph G is a pair (V, E) where V is a set of vertices or nodes, E is a set of edges that connect vertices
* Here is a graph G = (V, E)
* Each edge is a pair (v1, v2), where v1, v2 are vertices in V
* V = {A, B, C, D, E, F}
* E = {(A,B), (A,D), (B,C), (C,D), (C,E), (D,E)} 

<img class="img-responsive" src="https://acsariyildiz.github.io/images/py9.png">

There are two ways of representing graphs:
* The adjacency matrix representation
* The adjacency list representation 

## Adjacency Matrix Representation

<img class="img-responsive" src="https://acsariyildiz.github.io/images/py10.png">

## Adjacency List Representation

<img class="img-responsive" src="https://acsariyildiz.github.io/images/py11.png">

## Dijkstra Algorithm

<img class="img-responsive" src="https://acsariyildiz.github.io/images/py13.png">

## Exercises

<img class="img-responsive" src="https://acsariyildiz.github.io/images/py12.png">

* Represent the graph in Figure 1 using C++, Java, or any programming language that
you know.

* Write a program that implements Dijkstra algorithm which calculates the shortest path
from a starting node “S” to a goal node “G”. Use Dijkstra’s algorithm to find the cost
of the cheapest path between “S” and “G” in the above weighted graph. Describe at
each iteration the function L and set S.
