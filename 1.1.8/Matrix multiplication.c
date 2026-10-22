#include <stdio.h>

int main() {
    int m, n, n2, p;

    // Read dimensions and elements of matrix A
    scanf("%d %d", &m, &n);
    int A[100][100];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    // Read dimensions of matrix B
    scanf("%d %d", &n2, &p);

    // Check if multiplication is possible
    if (n != n2) {
        printf("Invalid input\n");
        return 0;
    }

    // Read elements of matrix B (only if valid)
    int B[100][100];
    for (int i = 0; i < n2; i++)
        for (int j = 0; j < p; j++)
            scanf("%d", &B[i][j]);

    // Compute product matrix C = A x B
    int C[100][100];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }

    // Print result
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
