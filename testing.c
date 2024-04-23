#include <stdio.h>
#include <stdlib.h>

// Function to perform Kruskal's algorithm
void kruskal(int graph[][100], int V);

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Comparison function for qsort
int compareEdges(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

// Function to find the set of an element i
int find(int parent[], int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Function to perform union of two subsets
void unionSets(int parent[], int rank[], int x, int y) {
    int xRoot = find(parent, x);
    int yRoot = find(parent, y);

    if (rank[xRoot] < rank[yRoot])
        parent[xRoot] = yRoot;
    else if (rank[xRoot] > rank[yRoot])
        parent[yRoot] = xRoot;
    else {
        parent[yRoot] = xRoot;
        rank[xRoot]++;
    }
}

int main() {
    int V;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int graph[100][100]; // Assuming a maximum of 100 vertices (you can adjust this)

    printf("Enter the adjacency matrix (%dx%d):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    kruskal(graph, V);

    return 0;
}

// Function to perform Kruskal's algorithm
void kruskal(int graph[][100], int V) {
    struct Edge edges[V * V];  // To store the resulting MST
    int E = 0;

    // Extracting edges from the adjacency matrix
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] != 0) {
                edges[E].src = i;
                edges[E].dest = j;
                edges[E].weight = graph[i][j];
                E++;
            }
        }
    }

    struct Edge result[V];  // To store the resulting MST
    int parent[V], rank[V];  // Arrays for disjoint set data structure

    // Initialize each node as a separate set
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    // Sort the edges in ascending order based on their weights
    qsort(edges, E, sizeof(edges[0]), compareEdges);

    int i = 0, e = 0;  // Index variables for sorted edges and result array

    while (e < V - 1 && i < E) {
        struct Edge nextEdge = edges[i++];

        int x = find(parent, nextEdge.src);
        int y = find(parent, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            unionSets(parent, rank, x, y);
        }
    }

    // Print the result
    printf("Minimum Spanning Tree:\n");
    for (i = 0; i < e; i++)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
}
