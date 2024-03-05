#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

struct Edge
{
    int x, y ;
    int w ;
};

void addheap(Edge heap[], int *n_things, Edge input)
{
    (*n_things) = (*n_things) + 1 ;
    int i = (*n_things) ; int j ;
    heap[i] = input ;
    Edge temp ;
    while(i>1)
    {
        j = i/2 ; //parent
        if(heap[i].w<heap[j].w)
        {
            temp = heap[j] ;
            heap[j] = heap[i] ;
            heap[i] = temp ;
            i = j ;
        }
        else break ;
    }
}

Edge delheap(Edge heap[], int *n_things)
{
    Edge root = heap[1] ;
    heap[1] = heap[(*n_things)] ;
    (*n_things) = (*n_things) - 1 ;

    int i = 1 ; int l, r ; Edge temp ;
    while(i<=(*n_things))
    {
        l = 2*i ; r = 2*i + 1 ;
        if(l<=(*n_things) && r<=(*n_things)) // left and right both exist
        {
            if(heap[i].w<=heap[l].w && heap[i].w<=heap[r].w) break ;
            else if(heap[l].w <= heap[r].w)
            {
                temp = heap[l] ;
                heap[l] = heap[i] ;
                heap[i] = temp ;
                i = l ;
            }
            else
            {
                temp = heap[r] ;
                heap[r] = heap[i] ;
                heap[i] = temp ;
                i = r ;
            }
        }
        else if(l<=(*n_things)) // only left
        {
            if(heap[l].w < heap[i].w)
            {
                temp = heap[l] ;
                heap[l] = heap[i] ;
                heap[i] = temp ;
                i = l ;
            }
            else
                break ;
        }
        else // leaf
            break ;
    }
    return root ;
}

typedef struct node *nodePtr ;
struct node
{
    Edge edge ;
    nodePtr link ;
};

int main()
{
    int n_vertex, n_edge ;
    cin >> n_vertex >> n_edge ;

    nodePtr graph[n_vertex] = {} ;

    Edge min_edge ;
    for(int i=0; i<n_edge; i++)
    {
        Edge edge ;
        cin >> edge.x >> edge.y >> edge.w ;
        if(i==0 || edge.w < min_edge.w)
        {
            min_edge = edge ;
        }
        nodePtr temp1 = (nodePtr)malloc(sizeof(node)) ;
        temp1->edge = edge ; temp1->link = graph[edge.x] ; graph[edge.x] = temp1 ;

        nodePtr temp2 = (nodePtr)malloc(sizeof(node)) ;
        temp2->edge = edge ; temp2->link = graph[edge.y] ; graph[edge.y] = temp2 ;
    }

    Edge heap[n_edge*2] ; int num_edges = 0 ;
    bool visited[n_vertex] = {} ;

    Edge new_edge = min_edge ;
    for(nodePtr ptr=graph[new_edge.x] ; ptr ; ptr=ptr->link)
    {
        addheap(heap, &num_edges, ptr->edge) ;
    }
    for(nodePtr ptr=graph[new_edge.y] ; ptr ; ptr=ptr->link)
    {
        addheap(heap, &num_edges, ptr->edge) ;
    }

    visited[new_edge.x] = 1 ; visited[new_edge.y] = 1 ;

    int sum = 0 ;
    sum = sum + new_edge.w ;

    for(int i=1; i<n_vertex-1; i++)
    {
        while( ! ( (visited[new_edge.x] == 1 && visited[new_edge.y] == 0) || (visited[new_edge.x] == 0 && visited[new_edge.y] == 1) )       )
            new_edge = delheap(heap, &num_edges) ;

        if(visited[new_edge.x] == 1 && visited[new_edge.y] == 0)
        {
            for(nodePtr ptr=graph[new_edge.y] ; ptr ; ptr=ptr->link)
            {
                addheap(heap, &num_edges, ptr->edge) ;
            }
            visited[new_edge.y] = 1 ;
        }
        if(visited[new_edge.x] == 0 && visited[new_edge.y] == 1)
        {
            for(nodePtr ptr=graph[new_edge.x] ; ptr ; ptr=ptr->link)
            {
                addheap(heap, &num_edges, ptr->edge) ;
            }
            visited[new_edge.x] = 1 ;
        }


        sum = sum + new_edge.w ;


    }

    cout << sum ;




}
