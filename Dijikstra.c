#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 6 // number of vertices

int graph[V][V] = {{0, 1, 4, 0, 0, 0},
                    {1, 0, 2, 5, 7, 0},
                    {4, 2, 0, 0, 1, 0},
                    {0, 5, 0, 0, 3, 8},
                    {0, 7, 1, 3, 0, 0},
                    {0, 0, 0, 8, 0, 0}}; // the graph as an adjacency matrix

int dist[V]; // array to store the shortest distance from source to each vertex
int visited[V]; // array to keep track of which vertices have been visited
int source = 0; // source vertex

// function to find the vertex with the minimum distance from the source
int findMinDistVertex() {
    int minDist = INT_MAX;
    int minVertex = -1;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] < minDist) {
            minDist = dist[i];
            minVertex = i;
        }
    }
    return minVertex;
}

void dijkstra() {
    // initialize all distances as infinity and visited as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    // distance from source to itself is 0
    dist[source] = 0;
    // loop through all vertices
    for (int i = 0; i < V; i++) {
        // find the vertex with the minimum distance from the source
        int u = findMinDistVertex();
        // mark the vertex as visited
        visited[u] = 1;
        // update the distance of all adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];            
        }
    }
}

void main() {
    dijkstra();
    printf("Shortest distances from source vertex %d:\n", source);
    for (int i = 0; i < V; i++) 
    printf("Vertex %d: %d\n", i, dist[i]);  
}

