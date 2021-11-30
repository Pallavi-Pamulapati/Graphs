// Kruskal(Graph G)
// {
//     sort(list of edges);

//     for (u,v,w) in List_of_Edges
//         find the parent(King :P) of u and v
//         if(parent(u) != parent(v))      // No cycle 
//             union(parent(u), parent(v)) based on rank // Increase kingdom
//             add list to the MST        
// }   


#include "bits/stdc++.h"
using namespace std;

struct edge_weight
{
    int A;
    int B;
    int weight;
};

bool Comparator(edge_weight edge1, edge_weight edge2)
{
    return (edge1.weight < edge2.weight);
}

int find(vector<edge_weight>& List_Edges,vector<int>& King,int num)
{
    if(King[num] != num)
    {
        King[num] = find(List_Edges,King,King[num]);
        return King[num];
    }
    else
    return num;
}

void Increase_Kingdom(int king,int oppo,vector<int>& Rank,vector<int>& King)    // union
{
    if(Rank[king] >= Rank[oppo])
    {
        King[oppo] = King[king];
        Rank[king] += Rank[oppo]; 
    }
    else
    {
        Rank[oppo] += Rank[king];
        King[king] = King[oppo];
    }
}

void MST(vector<edge_weight>& List_Edges,int E, int V)
{
    vector <int> King(V+1);
    vector<int> Rank(V+1);
    
    for(int i = 0;i < V+1;i++)
    {
        King[i] = i;
        Rank[i] = 1;
    }

    int ans = 0;
    for(int i = 0;i < E;i++)
    {
        int king = find(List_Edges,King,List_Edges[i].A);
        int opponent = find(List_Edges,King,List_Edges[i].B);
        if(king != opponent)
        {
            Increase_Kingdom(king,opponent,Rank,King);
            ans += List_Edges[i].weight;
        }
    }
    cout << ans << endl;

    return;
}

int main(void)
{
    int V,E;
    cin >> V >> E;
    
    vector <edge_weight> List_Edges(E+1);
 
    for(int i = 0;i < E;i++)
        cin >> List_Edges[i].A >> List_Edges[i].B >> List_Edges[i].weight;

    sort(List_Edges.begin(), List_Edges.end(), Comparator);
    
    MST(List_Edges, E, V);

    return 0;
}