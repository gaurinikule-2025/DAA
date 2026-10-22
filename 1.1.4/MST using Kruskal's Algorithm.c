#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



void kruskalMST(int **cost, int V) {

    int parent[V];
    int i, j, a, b, u, v;
    int min, mincost = 0;
    int edge = 0;

    for (i = 0; i < V; i++)
        parent[i] = i;

    while (edge < V - 1)
    {
        min = 9999;

        for (i = 0; i < V; i++)
        {
            for (j = i + 1; j < V; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        while (parent[u] != u)
            u = parent[u];
        while (parent[v] != v)
            v = parent[v];

        if (u != v)
        {
            parent[v] = u;
            printf("Edge %d:(%d, %d) cost:%d\n", edge, a, b, min);
            mincost += min;
            edge++;
        }

        cost[a][b] = cost[b][a] = 9999;
    }

    printf("Minimum cost= %d\n", mincost);
}






int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}
