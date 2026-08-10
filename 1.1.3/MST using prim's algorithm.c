#include <stdio.h>
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void prim(int graph[V][V], int vertices) {
	// Write your code here...
 int parent[V];
    int key[V];
    bool mstSet[V];

    // Initialize all vertices
    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
        parent[i] = -1;
    }

    // Start MST from vertex 0
    key[0] = 0;

    // Add vertices one by one to the MST
    for (int count = 0; count < vertices - 1; count++) {
        int u = minKey(key, mstSet, vertices);

        mstSet[u] = true;

        // Update keys of adjacent vertices
        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] != 0 &&
                !mstSet[v] &&
                graph[u][v] < key[v]) {

                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printTree(parent, graph, vertices);

}

int main() {
    int vertices;
    int graph[V][V];

    printf("No of vertices: ");
    scanf("%d", &vertices);

    printf("Adjacency matrix elements (row wise):\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    prim(graph, vertices);

    return 0;
}
