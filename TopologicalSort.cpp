/*Pseudo Code*/
// Topological_Sort(Graph G, int v, vector<bool> &status, stack <int>& stck)
// {
//     for every u ∈ Adj[v]        // for every adjacent node of v
//         if(status[u] == 0)  // if u is not visited
//             Topological_Sort(G,u,status,stck);
    
//     stck.push(v);     // push onto stack
//     status[v] = 1;      // mark v as visited

//     return;
// }

// vector<bool> status(V+1, 0);
// stack <int> stck;

// for every vertex v ∈ V
//     if(status[v] == 0)
//         Topological_Sort(G,v,status,stck);

#include "bits/stdc++.h"
using namespace std;

void Topological_Sort(vector<vector<int>> &Adj_List, int v, vector<bool> &status, stack <int>& stck)
{
    int neighbours = Adj_List[v].size();
    for(int i = 0;i < neighbours; i++)
    {
        if(status[Adj_List[v][i]] == 0)
            Topological_Sort(Adj_List, Adj_List[v][i], status, stck);
    }

    stck.push(v);
    status[v] = 1;

    return; 
}

int main(void)
{
    int V,E;        // N = number of vertices and E = number of edges

    cin >> V >> E;
    vector<vector<int>> Adj_List(V+1);      // graph
    int u,v; 

    for(int i = 0; i < E;i++)
    {
        cin >> u >> v; 
        Adj_List[u].push_back(v);       // => there is edge betweem u and v
    }

    vector<bool> status(V+1, 0);
    stack <int> stck;

    for(int v = 1; v < V + 1; v++)
    {
        if(status[v] == 0)
            Topological_Sort(Adj_List, v, status, stck);
    }

    while(!stck.empty())
    {
        cout << stck.top() << " ";
        stck.pop();
    }
    cout << endl;
    return 0;
}