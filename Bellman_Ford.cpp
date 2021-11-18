// Bellman_Ford(Graph G, int s, int V)
// {
//     vector<int> distance(V+1, INFINITE);
//     distance[s] = 0;

//     for(int i = 1;i < V; i++)
//         for every (u,v,w) ∈ E    // here w is the weight of the edge
//             if(distance[v] > distance[u] + w && distance[u] != INFINITE)
//                 distance[v] = distance[u] + w;
    
//     for every (u,v,w) ∈ E
//         if(distance[v] > distance[u] + w && distance[u] != INFINITE)
//         {   
//             cout << "Negative cycle detected" << endl;
//             return;
//         }
    // for(int i = 1;i <= V+1; i++)
    //     cout << distance[i] << " ";
    // cout << endl;

//     return;
// }
struct edge_weight
{
    int vertex;
    int weight;
};


#include "bits/stdc++.h"
using namespace std;
#define INFI 2147483647

void Bellman_Ford(vector<vector<edge_weight>> &Adj_List, int s, int V)
{
    vector<int> distance(V+1, INFI);
    distance[s] = 0;
    int Neighbours = 0;
    int check = 0;
    for(int i = 1; i < V; i++)
    {
        check = 0;
        for(int u = 1; u < V + 1; u++)
        {
            if(distance[u] == INFI)
                continue;

            Neighbours = Adj_List[u].size();
            for(int j = 0; j < Neighbours; j++)
            {
                if(distance[Adj_List[u][j].vertex] > distance[u] + Adj_List[u][j].weight)
                {
                    distance[Adj_List[u][j].vertex] = distance[u] + Adj_List[u][j].weight;
                    check = 1;
                }
            }
        }

        if(check == 0)
            break; 
    }

    for(int u = 1; u < V + 1; u++)
    {
        if(distance[u] == INFI)
            continue;

        Neighbours = Adj_List[u].size();
        for(int j = 0; j < Neighbours; j++)
        {
            if(distance[Adj_List[u][j].vertex] > distance[u] + Adj_List[u][j].weight)
            {
                cout << "Negative cycle detected" << endl;
                return;
            }
        }
    }

    for(int i = 1;i <= V; i++)
        if(distance[i] != INFI)
            cout << distance[i] << " ";
        else 
            cout << "Not Reachable" << " ";
    cout << endl;

    return; 
}

int main(void)
{
    int V, E, source;
    cin >> V >> E >> source;

    vector<vector<edge_weight>> Adj_List(V+1);
    int u, v, w;
    edge_weight edge;
    for(int i = 0;i < E; i++)
    {
        cin >> u >> v >> w;
        edge.vertex = v;
        edge.weight = w;

        Adj_List[u].push_back(edge);

        // edge.vertex = u;
        // Adj_List[v].push_back(edge);  // comment this line if the graph is directed
    }

    Bellman_Ford(Adj_List, source, V);

    return 0;
}