#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

void bfs(int, int, int [][SIZE], int []);

int main()
{
    int n, amat[SIZE][SIZE], source;
    int visited[SIZE] = {0};
    int i, j;

    printf("Enter number of vertices:\n");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &amat[i][j]);

    printf("The adjacency matrix is:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d\t", amat[i][j]);

        printf("\n");
    }

    printf("Give the source:\n");
    scanf("%d", &source);

    bfs(n, source, amat, visited);

    for (i = 0; i < n; i++)
    {
        if (visited[i] == 0)
            printf("%d is not reachable\n", i);
        else
            printf("%d is reachable\n", i);
    }

    return 0;
}

void bfs(int n, int source, int amat[][SIZE], int visited[])
{
    int q[SIZE], r = 0, f = 0, u, v;

    visited[source] = 1;
    q[r] = source;

    while (f <= r)
    {
        u = q[f++];

        for (v = 0; v < n; v++)
        {
            if ((amat[u][v] == 1) && (visited[v] == 0))
            {
                q[++r] = v;
                visited[v] = 1;
            }
        }
    }
}
