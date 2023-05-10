#include <stdio.h>
#include <stdlib.h>

// define constants
#define MAX_VERTICES 100
#define MAX_EDGES 5000

// define structures
typedef struct {
    int start;
    int end;
    int weight;
} Edge;

// define global variables
int parent[MAX_VERTICES];
Edge edges[MAX_EDGES];

// function prototypes
void make_set(int vertex);
int find_set(int vertex);
void union_sets(int vertex1, int vertex2);
int compare_edges(const void* a, const void* b);
void kruskal(int num_vertices, int num_edges);

int main() {
    int num_vertices = 6;
    int num_edges = 9;
    int i;

    // define edges
    edges[0].start = 1;
    edges[0].end = 2;
    edges[0].weight = 4;

    edges[1].start = 1;
    edges[1].end = 3;
    edges[1].weight = 2;

    edges[2].start = 2;
    edges[2].end = 3;
    edges[2].weight = 1;

    edges[3].start = 2;
    edges[3].end = 4;
    edges[3].weight = 5;

    edges[4].start = 3;
    edges[4].end = 4;
    edges[4].weight = 8;

    edges[5].start = 3;
    edges[5].end = 5;
    edges[5].weight = 10;

    edges[6].start = 4;
    edges[6].end = 5;
    edges[6].weight = 2;

    edges[7].start = 4;
    edges[7].end = 6;
    edges[7].weight = 6;

    edges[8].start = 5;
    edges[8].end = 6;
    edges[8].weight = 3;

    // run Kruskal's algorithm
    kruskal(num_vertices, num_edges);

    return 0;
}
// make a set containing a single vertex
void make_set(int vertex) {
    parent[vertex] = vertex;
}

// find the parent of a vertex using path compression
int find_set(int vertex) {
    if (parent[vertex] != vertex) {
        parent[vertex] = find_set(parent[vertex]);
    }
    return parent[vertex];
}

// merge two sets into a single set
void union_sets(int vertex1, int vertex2) {
    parent[find_set(vertex1)] = find_set(vertex2);
}

// compare edges by weight for sorting
int compare_edges(const void* a, const void* b) {
    Edge* edge1 = (Edge*)a;
    Edge* edge2 = (Edge*)b;
    return edge1->weight - edge2->weight;
}

// run Kruskal's algorithm
void kruskal(int num_vertices, int num_edges) {
    int i, num_trees = num_vertices;

    // initialize sets
    for (i = 1; i <= num_vertices; i++) {
        make_set(i);
    }

    // sort edges by weight
    qsort(edges, num_edges, sizeof(Edge), compare_edges);

    // loop over edges in increasing order of weight
    for (i = 0; i < num_edges && num_trees > 1; i++) {
        int start = edges[i].start;
        int end = edges[i].end;

        // check if start and end vertices are in different sets
        if (find_set(start) != find_set(end)) {
            printf("%d %d\n", start, end);
            union_sets(start, end);
            num_trees--;
        }
    }
}

