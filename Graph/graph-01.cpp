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

#include <bits/stdc++.h>
using namespace std;

class graph
{

public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        // direction = 0 : Undirected Graph
        // direction = 1 : Directed Graph

        // Create a edge from u to v(for both directed and undirected graph)
        adj[u].push_back(v); // u --> v edge

        // /Reverse edge exist only for udirected graph
        if (direction == 0)
        {
            adj[v].push_back(u); // v --> u edge
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << " --> ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }


    // Using Vector<vector<int>> GFG
    vector<vector<int>> printGraph(int V, vector<int> adj[]) {
            vector<vector<int>> ans;

            for(int i = 0 ; i<V ; i++){
                vector<int> a;
                a.push_back(i); //--> Nodes

                for(int j = 0 ; j<adj[i].size() ; j++){
                    a.push_back(adj[i][j]); //Edgest list
                }
                ans.push_back(a);
            }
            return ans;

    }
};

// BFS Traversal in Graph

// unordered-map : Visited(Keeps track of visited nodes) --> All are initially false , if visited then true
// Queue : FIFO

// Front Node = 0
// Make queue and push the first source node
// visited(0) == true
// Print front Node
// see adjacent nodes of 0 and 0 is removed from front node

// front node : 3
// Push 3
// vistied(3);
// print front node
// see adjacent nodes of 3 (If not visisted add to queue) and remove 3 from front node

// Repeat same process

// Do it while queue is empty


// When some nodes are not connected : Disconnected graph

// given : Source Node : 0
vector<int> bfsTraversal(int V/**No of nodes*/ , vector<int> adj[] /**List of edges*/){
    vector<int> result;
    queue<int> q;

    q.push(0);

    int visited[V] = {0};

    visited[0] = 1;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        result.push_back(node);

        for(auto a : adj[node]){
            if(!visited[a]){
                q.push(a);
                visited[a] = 1;
            }
        }
    }

    return result;

}

int main()
{
    int n;
    cout << "No of nodes : ";
    cin >> n;

    int m;
    cout << "No of edges : ";
    cin >> m;

    graph g;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // Creating a undirected graph
        g.addEdge(u, v, 0);
    }

    g.printAdjList();

    return 0;
}
