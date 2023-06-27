// Graph Intro
// Type of DS : combination of nodes and edges

// Types : Directed and undirected Graph

// Node : Entity to store data
// Edge : connecting nodes

// Degree : No of edges connected to that node

// in case of directed graoh : In degree & out Degree

// Weighted Graph : Edges contains some weight
// If no weight , then all edges can be assumed to have 1 weight (for both directed and undirected graph)

// Path : Sequence of Nodes

// Cyclic Directed Graph : if cycle formed (if weight given then weighted)
// Acyclic Directed graph : No cycles fomed (if weight given then weighted)

// Representation :
// 1) Adjancency matrix
// 2 ) adjacency list

// 1) Adjancency matrix : Input : no of nodes , no of edges , list of edges

// Make a 2D matrix (no of nodes x no of nodes size)

// fill the matrix if that edge is present else 0
//   0 1 2
// 0 0 1 0
// 1 0 0 1
// 2 1 0 0

// Space complexity : O(n2) ( Implemented Using 2 for loops)

// 2) Adjancency list : Input : no of nodes , no of edges , list of edges

// Write all the list of edges in the respective node
// 0  -->  1 , 4
// 1  --> 0 , 2 , 3
// 2  --> 1 , 3
// 3  --> 1 , 2 , 4
// 4  --> 0 , 3

// Implementation : left side (single entity (int , string etc))  right side (list of objects (vector , list etc))

// Eg

// Make a map : Key : int m , value : list<int> --> More prefereed
// map<int , list<int>>

// can alos be implemented using vector<vector<int>
