// Prims(Graph G)
// {
//     vertex_value priority_q[V]; // creating the priority queue
//     int positions[V];   // array that keep track of positions in priority queue
//     int value = 0;     // value of the MST
//     for i in V:     // initializing the distances
//         priority_q[i].vertex = i+1;
//         positions[i] = i;
//         if(i+1 != 1)
//             priority_q[i].value = INFINITY;
//         else 
//             priority_q[i] = 0;
    
//     UP_Heapify with respective the vertex 1

//     while queue is not empty
//         min_node = exctract min value from priority_q
//         swap(min_node, last node)
//         size_of_queue--
//         Down_Heapify(root)

//         for v in Adj_list[u]:  // here w is distance between u and v
//             if(value(v) > w)
//                 value(v) = w;
//                 UP_Heapify(v);
//         value += min_node.value;
// }

#include "bits/stdc++.h"
using namespace std;
#define INFI 2147483647

struct vertex_value{
    int vertex;
    int value;
};

void Swap(vertex_value* a, vertex_value* b)
{
    vertex_value temp = *a;
    *a = *b;
    *b = temp;

    return;
}

void UP_Heapify(vertex_value* priority_q, int* positions, int v)
{
    while(v != 0)   // that is, if it is not the root node.
    {
        if(priority_q[v].value < priority_q[(v-1)/2].value)       // if parent is larger than child
        {
            // swap the positions
            positions[priority_q[v].vertex - 1] = (v-1)/2;
            positions[priority_q[(v-1)/2].vertex - 1] = v;

            Swap(&priority_q[(v-1)/2], &priority_q[v]);

            v = (v-1)/2;   // now parent is swaped with the child
        }
        else 
            break;
    }

    return;
}

void Down_Heapify(vertex_value* priority_q, int* positions, int v, int size)
{
    if(size == 1)
        return; 
    int l_index = 2*v + 1;
    while(l_index < size)
    {
        if(l_index + 1 < size && priority_q[l_index].value > priority_q[l_index + 1].value)
            l_index++;
        
        if(priority_q[v].value <= priority_q[l_index].value)
            return;
        
        positions[priority_q[l_index].vertex - 1] = v;
        positions[priority_q[v].vertex - 1] = l_index;

        Swap(&priority_q[v], &priority_q[l_index]);

        v = l_index;
        l_index = 2*v + 1;   
    }

    return;
}

void Prims(vector<vector<vertex_value>> &Adj_List, int V)
{
    vertex_value priority_q[V];
    vertex_value min_node;

    int positions[V];

    for(int i = 0;i < V;i++)
    {
        priority_q[i].vertex = i+1;
        positions[i] = i;
        if(i+1 != 1)
            priority_q[i].value = INFI;
        else 
            priority_q[i].value = 0;
    }

    int size = V;

    UP_Heapify(priority_q, positions, 0);
    int value = 0;
    while(size != 0)
    {
        min_node = priority_q[0];
        size--;
        positions[priority_q[size].vertex - 1] = 0;
        positions[priority_q[0].vertex -1] = size;

        Swap(&priority_q[0],&priority_q[size]);
        Down_Heapify(priority_q, positions, 0, size);

        
            int Neighbours = Adj_List[min_node.vertex].size();

            for(int i = 0;i < Neighbours; i++)
            {
                if(positions[Adj_List[min_node.vertex][i].vertex - 1] < size && priority_q[positions[Adj_List[min_node.vertex][i].vertex -1]].value > Adj_List[min_node.vertex][i].value)
                {
                    priority_q[positions[Adj_List[min_node.vertex][i].vertex -1]].value =  Adj_List[min_node.vertex][i].value; 
                    UP_Heapify(priority_q, positions, positions[Adj_List[min_node.vertex][i].vertex -1]);
                }
            }

        value += min_node.value;        
    }

    cout << value << endl;
}

int main(void)
{
    int V,E; 
    cin >> V >> E;

    vector<vector<vertex_value>> Adj_List(V+1);
    int u, v, w;

    vertex_value edge; 

    for(int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        edge.value = w;
        edge.vertex = v;

        Adj_List[u].push_back(edge);

        edge.vertex = u;
        Adj_List[v].push_back(edge);
    }

    Prims(Adj_List, V);

    return 0;
}