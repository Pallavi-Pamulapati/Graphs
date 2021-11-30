// DFS(Graph G, int V)
// {
//    // status[i] = 0 => not visited, 1 => seen, 2 => visited
//     int check = 0;
//     int status[V + 1] = {0}; // V = no.of vertices
//     for every vertex v ∈ V  // V = set of vertices of G
//         if(status[v] == 0)
//              check = DFS_Traversal(G, v, status);    // initially the vertex does not have parent
//              if(check == 1)
//                  return 1;
//     return 0;
// }

// DFS_Traversal(Graph G, int v, int* status)
// {
//     status[v] = 1;
//     int check = 0;
//     for every u ∈ Adj[v]      // => there is a vertex from v to u
//         if(status[u] == 0)    // if the vertex is not visited we perform DFS
//         {
//             check = DFS_Traversal(G,u,status);
//             if(check == 1);   // return if there is a cycle
//                 return;
//         }
//         else if neighbour is seen 
//             return 1;            // we return 
//     status[v] = 2;
//     return 0;
// }

// code 

#include <bits/stdc++.h>
using namespace std;

bool DFS_Traversal(vector<vector<int>> &Adj_List, int i, vector<int> &status)
{
    status[i] = 1; 
    int check = 0;
    int Neighbours = Adj_List[i].size();
    for(int j = 0; j < Neighbours;j++)
    {
        if(status[Adj_List[i][j]] == 0)
        {    
            check = DFS_Traversal(Adj_List,Adj_List[i][j], status);
            if(check == 1)
                return 1;
        }
        else if(Adj_List[i][j] == 1)
            return 1;
    }

    status[i] = 2;
    return 0;
}

bool DFS(vector<vector<int>> &Adj_List, int V)
{
    vector<int> status(V+1, 0);  // initializing status of all the vertices to 0
    int check = false;
    for(int i = 1;i < V+1; i++)
    {
        if(status[i] == 0)
            check = DFS_Traversal(Adj_List, i, status);
        
        if(check == true)
            return true;
    }

    return false;
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
    }

    int check = DFS(Adj_List, V); 
    
    if(check == 1)
        cout << "Cyclic Graph" << endl;
    else 
        cout << "Acyclic Graph" << endl;

    return 0;
}