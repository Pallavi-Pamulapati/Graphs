// DFS(Graph G, int V)
// {
//     // status[i] = 0 => not visited, 1 => seen, 2 => visited
//     int status[V + 1] = {0}; // V = no.of vertices
//     for every vertex v ∈ V  // V = set of vertices of G
//         if(status[v] == 0)
//             DFS_Traversal(G, v, status);
    
//     return;
// }

// DFS_Traversal(Garph G, int v, int* status)
// {
//     status[v] = 1;
//     for every u ∈ Adj[v]      // => there is a vertex from v to u
//         if(status[u] == 0)
//             DFS_Traversal(G,u,status);
//     status[v] = 2;

//     return;
// }

// code 

#include <bits/stdc++.h>
using namespace std;

void DFS_Traversal(vector<vector<int>> &Adj_List, int i, vector<int> &status)
{
    status[i] = 1; 
    cout << i << " ";
    int Neighbours = Adj_List[i].size();
    for(int j = 0; j < Neighbours;j++)
    {
        if(status[Adj_List[i][j]] == 0)
            DFS_Traversal(Adj_List,Adj_List[i][j], status);
    }

    status[i] = 2;

    return;
}

void DFS(vector<vector<int>> &Adj_List, int V)
{
    vector<int> status(V+1, 0);  // initializing status of all the vertices to 0
    
    for(int i = 1;i < V+1; i++)
    {
        if(status[i] == 0)
            DFS_Traversal(Adj_List, i, status);
    }

    return;
}

int main(void)
{
    int V,E;        // N = number of vertices and E = number of edges

    cin >> V >> E;
    vector<vector<int>> Adj_List(V+1);
    int u,v; 

    for(int i = 0; i < E;i++)
    {
        cin >> u >> v; 
        Adj_List[u].push_back(v);       // => there is edge betweem u and v
        // Adj_List[v].push_back(u);    // if the graph is undirected
    }

    DFS(Adj_List, V); 
    cout << endl;
    return 0;
}