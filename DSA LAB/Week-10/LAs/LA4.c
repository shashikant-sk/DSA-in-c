// WAP to check whether an undirected graph is connected or not using DFS
#include <stdio.h>

int vertices = 0, edges = 0;

void addEdge(int Adj[][vertices], int m, int n)
{
    Adj[m][n] = Adj[n][m] = 1;
}

void printAdjMatrix(int Adj[][vertices])
{
    printf("\nThe Adjacency matrix: \n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
            printf("%d ", Adj[i][j]);
        printf("\n");
    }
}

void DFStraverse(int u, int visited[], int Adj[][vertices])
{
    visited[u] = 1;
    for (int v = 0; v < vertices; v++)
        if (Adj[u][v])
            if (!visited[v])
                DFStraverse(v, visited, Adj);
}

int isConnected(int Adj[][vertices])
{
    int vis[vertices];
    for (int u = 0; u < vertices; u++)
    {
        for (int i = 0; i < vertices; i++)
            vis[i] = 0;

        DFStraverse(u, vis, Adj);

        for (int i = 0; i < vertices; i++)
            if (!vis[i])
                return 0;
    }
    return 1;
}

int main()
{
    // { { 1, 2 }, { 2, 3 }, { 4, 5 }, { 1, 5 } }
    int choice = 1;
    printf("Enter number of vertices of undirected graph: ");
    scanf("%d", &vertices);
    int Adj[vertices][vertices];
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            Adj[i][j] = 0;
    while (choice != 0)
    {
        int m, n;
        printf("Enter 2 vertices to form edge: ");
        scanf("%d %d", &m, &n);
        addEdge(Adj, m, n);
        edges++;
        printf("Enter 1 to continue or 0 to exit: ");
        scanf("%d", &choice);
    }
    printAdjMatrix(Adj);
    isConnected ? printf("Graph is connected!\n") : printf("Graph is not connected!\n");
    return 0;
}