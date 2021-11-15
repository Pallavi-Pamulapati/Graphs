// BFS(Graph G, int V)
// {
//     vector<int> status(V+1, 0);     // status array
//     queue<int> que;         // queue 
//     for every vertex s ∈ V  // V = set of vertices of G
//         if(status[s] == 0)
//             que.push(s);
//             status[s] = 1;
//             BFS_Traversal(G, status, que);

//     return;
// }

// BFS_Traversal(Graph G, vector<int> &status, queue<int> &que)
// {
//     while queue is not empty
//         int v = que.front();
//         que.pop();
//         // pushing the neighbours of v into queue
//         for every u ∈ Adj[v]      // => there is a vertex from v to u
//             if(status[u] == 0)
//                 que.push(u);
//                 status[u] = 1;      // u is seen

//         status[v] = 2;          // v is visited
    
//     return;
// }


#include "bits/stdc++.h"
using namespace std;

void BFS_Traversal(vector<vector<int>> &Adj_List, vector<int> &status, queue<int> &que)
{
    while(que.size() > 0)
    {
        int v = que.front();
        que.pop();

        int neighbours = Adj_List[v].size();

        for(int i = 0;i < neighbours; i++)
        {
            if(status[Adj_List[v][i]] == 0)
            {
                que.push(Adj_List[v][i]);
                status[Adj_List[v][i]] = 1;
            }
        }

        status[v] = 2;
        cout << v << " "; 
    }

    return; 
}

void BFS(vector<vector<int>> &Adj_List, int V)
{
    vector<int> status(V+1, 0);
    queue<int> que;

    for(int s = 1; s < V+1; s++)
    {
        if(status[s] == 0)
        {
            que.push(s);
            status[s] = 1;
            BFS_Traversal(Adj_List, status, que);
        }
    }

    return;
}

int main(void)
{
    int V,E;
    cin >> V >> E;
    vector<vector<int>> Adj_List(V+1);
    int u,v; 

    for(int i = 0; i < E;i++)
    {
        cin >> u >> v; 
        Adj_List[u].push_back(v);       // => there is edge betweem u and v
        Adj_List[v].push_back(u);    // if the graph is undirected else comment this line
    }

    BFS(Adj_List, V);
    cout << endl;
    return 0;
}