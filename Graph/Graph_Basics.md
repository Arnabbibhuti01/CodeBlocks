# Graph Basics

<ins>**Nodes:**</ins> These are the states or vertices

<ins>**Edges:**</ins> These are the links between vertices
        They are of two types: 
            - *directed:* where edges are only one way
            - *undirected:* where edges are two way  

<ins>**Adjacency Matrix:**</ins> It is a way to represent our graph using a 2D vector. 
                    Say if adj represents our adjacency matrix, then adj[i][j] = 1
                    represents that there is an edge from node i to node j.

<ins>**Adjacency List:**</ins> It is another way of representing our graph. Here we have an 
                    array of lists, where list i contains the immediate neighbours of 
                    i in the graph.

<ins>**In-degree of a vertex:**</ins> It is the number of incoming edges to a node.

<ins>**Out-degree of a vertex:**</ins> It is the number of outgoing edges from a node.

<ins>**Connected Graph:**</ins> Each node has path from every other node.

<ins>**Disconnected Graph:**</ins> Each node does not have a path from every other node.

<ins>**Cycle:**</ins> Path from a vertex to the same vertex in a graph is called cycle.

<ins>**Tree:**</ins> A connected acyclic graph 

<ins>**Complete Graph:**</ins> A graph in which each vertex each vertex is 
                    directly connected to every other vertex.




