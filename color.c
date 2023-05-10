#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define V 4 // number of vertices in the graph

void printSolution(int color[]);

// checks whether it is safe to color vertex v with c
bool isSafe(int v, bool graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

// recursive function to solve graph coloring problem
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v) {
    // base case: all vertices are assigned a color
    if (v == V) {
        return true;
    }

    // try all possible colors for vertex v
    for (int c = 1; c <= m; c++) {
        // check if it is safe to color vertex v with color c
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            // recur for next vertex
            if (graphColoringUtil(graph, m, color, v+1)) {
                return true;
            }
            // if assigning color c doesn't lead to a solution, backtrack
            color[v] = 0;
        }
    }
    return false;
}

// wrapper function to solve graph coloring problem
int graphColoring(bool graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++) {
        color[i] = 0;
    }

    if (graphColoringUtil(graph, m, color, 0)) {
        printf("Solution exists with %d colors:\n", m);
        printSolution(color);
        return m;        
    } else {
        return -1;
    }
}

// utility function to print solution
void printSolution(int color[]) {
    for (int i = 0; i < V; i++) {
        printf("Vertex %d ---> Color %d\n", i, color[i]);
    }
}

int main() {
    // define graph adjacency matrix
    bool graph[V][V] = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}
    };

    // solve graph coloring problem with 3 colors
    for(int i=0;i<INT_MAX;i++)
    {
      if(graphColoring(graph, i)!=-1)            
        break;      
    }

    return 0;
}
