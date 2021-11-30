// for u in V:         // initilaize the distance matrix
//     for v in V: 
//         if(j == i)
//             distance[i][j] = 0;
//         else
//             distance[i][j] = INFINITY; 

// for (u,v,w) ∈ E:        // When there are no intermediate vertices
//     distance[u][v] = min(w, distance[u][v]); 

// for n in V:     // n is the intermediate node
//     for u in V:     // updating the values of the matrix
//         for v in V: 
//             distance[u][v] = min(distance[u][v], distance[u][n] + distance[n][v]); 

#include "bits/stdc++.h"
using namespace std;
#define INFI 2147483647

void Floyd_Warshall(vector<vector<int>> &distance, int V)
{
    for(int n = 1;n < V+1; n++)
    {
        for(int u = 1; u < V+1; u++)
        {
            if(u == n)
                continue;
            for(int v = 1; v < V+1; v++)
            {
                if(v == n)
                    continue;

                if(distance[u][n] != INFI && distance[n][v] != INFI)
                distance[u][v] = min(distance[u][v], distance[u][n] + distance[n][v]);
            }
        }
    }

    for(int i = 1;i < V+1; i++)
    {
        for(int j = 1;j < V+1; j++)
            cout << distance[i][j] << " ";
        cout << endl;
    }
}

int main(void)
{
    int V, E;
    cin >> V >> E; 

    vector<vector<int>> distance(V+1, vector<int> (V+1));

    for(int u = 1;u <= V; u++)
    {
        for(int v = 1; v < V+1; v++)
        {
            if(u == v)
            distance[u][v] = 0;
            else 
            distance[u][v] = INFI;
        }
    }

    int u,v,w;

    for(int i = 0;i < E;i++)
    {
        cin >> u >> v >> w;

        distance[u][v] = min(w, distance[u][v]);
        // distance[v][u] = distance[u][v]   // uncomment this line when the graph is undirected
    }

    Floyd_Warshall(distance, V); 

    return 0;
}