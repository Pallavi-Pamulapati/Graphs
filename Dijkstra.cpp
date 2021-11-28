/*
Dijkstra(Graph G, int source, int V)
{
    edge_weight pque[V]; // creating the priority queue
    int positions[V];   // Array that keep track of positions in priority queue

    for i in V:     // initializing the distances
        pque[i].vertex = i+1;
        positions[i] = i;
        if(i+1 != s)
            pque[i].weight = INFINITY;
        else 
            pque[i].weight = 0;
    
    UP_Heapify with respective the source vertex

    while queue is not empty 
        min_node = exctract min value from pque
        swap(min_node, last node)
        size_of_queue--
        Down_Heapify(root)
        if(distance(u) != INFINITY) // here u is the vertex of min_node
            for every (u,v,w) ∈ E    
                if(distance(v) > distance(u) + w)
                    distance(v) = distance(u)+w
                    UP_heapify(v)
    
    // printing the distances
    for(int i = 0; i < V; i++)
        cout << pque[positions[i]].weight << " ";
    cout << endl;  
} 
*/

#include "bits/stdc++.h"
using namespace std;
#define INFI 2147483647
 
struct edge_weight
{
    int vertex;
    int weight;
};

void Swap(edge_weight* a, edge_weight* b)
{
    edge_weight temp = *a;
    *a = *b;
    *b = temp;

    return;
}

void UP_Heapify(edge_weight* pque, int* positions, int v)
{
    while(v != 0)   // that is, if it is not the root node.
    {
        if(pque[v].weight < pque[(v-1)/2].weight)       // if parent is larger than child
        {
            // swap the positions
            positions[pque[v].vertex - 1] = (v-1)/2;
            positions[pque[(v-1)/2].vertex - 1] = v;

            Swap(&pque[(v-1)/2], &pque[v]);

            v = (v-1)/2;   // now parent is swaped with the child
        }
        else 
            break;
    }

    return;
}

void Down_Heapify(edge_weight* pque, int* positions, int v, int size)
{
    if(size == 1)
        return; 
    int l_index = 2*v + 1;
    while(l_index < size)
    {
        if(l_index + 1 < size && pque[l_index].weight > pque[l_index + 1].weight)
            l_index++;
        
        if(pque[v].weight <= pque[l_index].weight)
            return;
        
        positions[pque[l_index].vertex - 1] = v;
        positions[pque[v].vertex - 1] = l_index;

        Swap(&pque[v], &pque[l_index]);

        v = l_index;
        l_index = 2*v + 1;   
    }

    return;
}

void Dijkstra(vector<vector<edge_weight>> &Adj_List, int V, int s)
{

    // creating Priority queue
    edge_weight pque[V]; 
    edge_weight min; 
    int positions[V];

    for(int i = 0;i < V;i++)
    {
        pque[i].vertex = i+1;
        positions[i] = i;
        if(i+1 != s)
            pque[i].weight = INFI;
        else 
            pque[i].weight = 0;
    }
    
    int size = V;

    UP_Heapify(pque, positions, s-1);

    while(size != 0)
    {
        min = pque[0];
        size--;
        positions[pque[size].vertex - 1] = 0;
        positions[pque[0].vertex -1] = size;

        Swap(&pque[0],&pque[size]);
        Down_Heapify(pque, positions, 0, size);

        if(min.weight != INFI)
        {
            int Neighbours = Adj_List[min.vertex].size();

            for(int i = 0;i < Neighbours; i++)
            {
                if(positions[Adj_List[min.vertex][i].vertex - 1] < size && pque[positions[Adj_List[min.vertex][i].vertex -1]].weight > min.weight + Adj_List[min.vertex][i].weight)
                {
                    pque[positions[Adj_List[min.vertex][i].vertex -1]].weight =  min.weight + Adj_List[min.vertex][i].weight; 
                    UP_Heapify(pque, positions, positions[Adj_List[min.vertex][i].vertex -1]);
                }
            }
        }
    }

    // printing the list
    for(int i = 0; i < V; i++)
        cout << pque[positions[i]].weight << " ";
    cout << endl;
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

       
        edge.vertex = u;
        // Adj_List[v].push_back(edge);  // comment this line if the graph is directed
    }

    Dijkstra(Adj_List, V, source);

    return 0;
}